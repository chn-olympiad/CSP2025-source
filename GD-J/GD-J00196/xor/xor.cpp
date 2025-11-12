#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int s=1;s<=n;s++){
		for(int i=1;i<=n;i++){
			if(vis[i]!=0){
				i=vis[i]+1;
			}
			int cnt=a[i];
			if(a[i]==0){
				vis[i]=i;
				continue;
				}
			for(int j=i;j<=i+s-1;j++){
				if(j>n){
					break;
				}
				
				if(vis[i]!=0){
					if(vis[i]==n){
						cout<<ans<<endl;
						return 0;
					}
					s=1;
					break;
				}
				if(i!=j)
				cnt^=a[j];
				if(cnt==k){
					for(int r=i;r<=j;r++){
						vis[r]=j;
					}
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
