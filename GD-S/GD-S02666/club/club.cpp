#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int T;
int n;
int maxn,maxx=-1;
int Aflag,Bflag;
long long ans;
int likes[5][MAXN],vis[MAXN];
int cnts[5];
long long sum[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		maxx=-1;
		maxn=n/2;
		Aflag=Bflag=0;
		ans=0;
		memset(likes,0,sizeof(likes));
		memset(vis,0,sizeof(vis));
		memset(cnts,0,sizeof(cnts));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			cin>>likes[1][i]>>likes[2][i]>>likes[3][i];
			if(likes[2][i]!=likes[3][i]) Aflag=1;
			if(likes[3][i]!=0) Bflag=1;
		}
		if(!Aflag){
			sort(likes[1]+1,likes[1]+1+n);
			for(int i=n;i>=n/2;i--) ans+=likes[1][i];
		}
		else if(!Bflag){
			sort(likes[1]+1,likes[1]+1+n);
			sort(likes[2]+1,likes[2]+1+n);
			for(int i=n;i>=1;i--){
				if(cnts[1]>=maxn&&cnts[2]>=maxn) break;
				maxx=max(likes[1][i],likes[2][i]);
				if(maxx==likes[1][i]&&cnts[1]<maxn){
					ans+=maxx;
					cnts[1]++;
				}
				else if(maxx==likes[2][i]&&cnts[2]<maxn){
					ans+=likes[2][i];
					cnts[2]++;
				}
				else if(likes[1][i]==likes[2][i]){
					for(int j=1;j<=n;j++){
						sum[1]+=likes[1][i];
						sum[2]+=likes[2][i];
					}
					if(sum[1]>sum[2]){
						ans+=maxx;
						cnts[1]++;
					}
					else{
						ans+=likes[2][i];
						cnts[2]++;
					} 
				}
			}
		}
		else{
			for(int k=1,ki,kj;k<=n;k++){
				maxx=-1;
				for(int i=1;i<=n;i++){
					if(vis[i]) continue;
					for(int j=1;j<=3;j++){
						if(maxx<likes[j][i]){
							maxx=likes[j][i];
							ki=i;
							kj=j;
						}
					}
				}
				if(cnts[kj]<maxn){
					vis[ki]=1;
					cnts[kj]++;
					sum[kj]+=likes[kj][ki];
				}
			}
			ans=sum[1]+sum[2]+sum[3];
		}
		cout<<ans<<endl;
	}
	return 0;
}
