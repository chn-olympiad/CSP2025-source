#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000000],zz,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int t=0;
			for(int f=i;f<=j;f++){
				t^=a[f];
			}
			if(t==k){
				if(i>zz){
					ans++;
					zz=j;
				}
			}
		}
	}
	cout<<ans;
	return 0;
	
}
