#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0,p=1;
long long a[500005];
bool vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(vis,0,sizeof(vis));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(k==0){
			if(a[i]==a[i+1]&&vis[i]==0&&vis[i+1]==0&&a[i]==1&&a[i+1]==1){
				vis[i]=1;
				vis[i+1]=1;
				ans++;
			}
			else if(a[i]==0){
				ans++;
			}
		}
		else if(k==1){
			if(a[i]==1){
				ans++;
			}
		}
		else{
			if(a[i]==k&&vis[i]==0){
				ans++;
				vis[i]=1;
			}
			long long t=a[i];
			for(int j=i+1;j<=i+p;j++){
				t^=a[j];
				if(vis[j]==0&&vis[i]==0&&t==k&&i+p<=n&&vis[i+p]==0){
					vis[j]=1;
					vis[i]=1;
					ans++;
				}
			}
			if(p+i>i){
				p++;
			}
		}
    }
	cout<<ans;
	return 0;
}