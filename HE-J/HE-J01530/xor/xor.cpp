#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int h=0,p=1;
			for(int p=i;p<=j;p++){
				h=h^a[p];
				if(a[p]==-1){
					p=0;
					break;
				}
			}
			if(h==k&&p==1){
				for(int l=i;l<=j;l++){
					a[l]=-1;
				}
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
