#include<bits/stdc++.h>
using namespace std;
int const maxn=5e5+5;
long long n,k;
long long a[maxn];
long long ans=0;
int vis[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset (vis,0,sizeof(vis));
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int numm=0,cnt=0;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (i==j&&a[i]==k){
				if (vis[i]==0){
					ans++;
					vis[i]=1;
				}
			}
			else{
				int y=0;
				numm=0,cnt=0;
				for (int x=i;x<=j;x++){
					numm++;;
					y^=a[x];
				}
				for (int p=i;p<=j;p++){
					if (vis[p]==0){
						cnt++;
					} 
				}
				if(y==k&&numm==cnt){
					ans++;
					for (int t=i;t<=j;t++){
						vis[t]=1;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
