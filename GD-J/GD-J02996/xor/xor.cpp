#include<bits/stdc++.h>
using namespace std;
int a[500010];
bool c[500010];
int s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)ans++,c[i]=1;
	}
	
	for(int i=1;i<=n;i++){
		if(c[i]==1)continue;
		s=a[i];
		for(int j=i+1;j<=n;j++){
			if(c[j]==1){
				s=s^a[j];
				if(s==k){
					for(int z=i;z<=j;z++){
						c[z]=1;
					}
					ans++;
					break;
				}
			}
			
		}
	}
	cout<<ans;
	return 0;
}
