#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans,a[N][15],cnt[15],id[N],f[N],maxn[N],vis[N],T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		memset(f,0,sizeof(f));
		memset(maxn,0,sizeof(maxn));
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++){
			int maxn=0;
			id[i]=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				cnt[j]=n/2;
			}
		}
	int cntt=n;
	while(cntt){
			for(int j=1;j<=3;j++){
				if(cnt[j]==0)continue;
				maxn[j]=0;
				id[j]=0;
				for(int i=1;i<=n;i++){
					if(f[i]==0){
							if(a[i][j]>maxn[j]){
							maxn[j]=a[i][j];
							id[j]=i;
						}	
					}
				}
			}
			int sum=0;
			memset(vis,0,sizeof(vis));
			for(int j=1;j<=3;j++){
				if(cnt[j]==0)continue;
				if(vis[id[j]]==0){
					vis[id[j]]=j;
					sum+=maxn[j];
					cnt[j]--;
					f[id[j]]=1;
					cntt--;
				}
				else{
					if(maxn[vis[id[j]]]<maxn[j]){
						cnt[vis[id[j]]]++;
						sum-=maxn[vis[id[j]]];
						vis[id[j]]=j;
						sum+=maxn[j];
						cnt[j]--;
						f[id[j]]=1;
					}
				}
			}
			ans+=sum;
		}
		cout<<ans<<endl;	
	}
	return 0;
}
