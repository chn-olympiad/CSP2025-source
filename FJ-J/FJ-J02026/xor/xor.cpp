#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500100];
int num=0;
int vis[500100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			num++;
			cnt++;
			vis[cnt]=i;
		}
	}
	for(int j=1;j<=cnt+1;j++){
		if(j==cnt+1){
			for(int l=vis[j-1]+1;l<n;l++){
				for(int r=l+1;r<=n;r++){
					int ans=0;
					for(int i=l;i<=r;i++){
						ans=ans xor a[i];
					}
					if(ans==k){
						num++;
						l=r+1;
						r++;
					}
				}
			}
		}
		else for(int l=vis[j-1]+1;l<vis[j];l++){
			for(int r=l+1;r<vis[j];r++){
				int ans=0;
				for(int i=l;i<=r;i++){
					ans=ans xor a[i];
				}
				if(ans==k){
					num++;
					l=r+1;
					r++;
				}
			}
		}
	}
	cout<<num<<"\n"; 
	return 0;
}
