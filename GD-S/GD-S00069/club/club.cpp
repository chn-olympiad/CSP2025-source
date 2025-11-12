#include<bits/stdc++.h>
using namespace std;
int t,a[100005][5],n,cnt[5],dp[100005][5][5],p[100005];
long long ans;
bool vis[100005];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > >> q;
signed main(){ 
	freopen("club2.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(register int i=0;i<=n+3;i++){
			p[i]=0;
			vis[i]=0;
			for(register int j=0;j<3;j++){
				for(register int k=0;k<3;k++){
					dp[i][j][k]=0;
				}
			}
		}
		while(!q.empty()){
			q.pop();
		}
		for(register int i=0;i<3;i++){
			cnt[i]=0;
		}
		for(register int i=1;i<=n;i++){
			int maxx=0;
			for(register int j=0;j<3;j++){
				cin>>a[i][j];
				maxx=max(maxx,a[i][j]);
			}
			int id=0;
			for(register int j=0;j<3;j++){
				if(a[i][j]==maxx){
					cnt[j]++;
					id=j;
					p[i]=id;
					break;
				}
			}
			for(register int j=0;j<3;j++){
				dp[i][id][j]=maxx-a[i][j];
				dp[i][j][id]=maxx-a[i][j];
			}
			ans+=maxx;
		}
		int wr=-1;
		for(register int i=0;i<3;i++){
			if(cnt[i]>n/2){
				wr=i;
				break;
			}
		}
		if(wr==-1){
			cout<<ans<<'\n';
		}
		else{
			for(register int i=1;i<=n;i++){
				if(p[i]==wr){
					for(register int j=0;j<3;j++){
						if(j!=wr){
							q.push(make_pair(dp[i][wr][j],make_pair(i,j)));
						}
					}
				}
			}
			while(cnt[wr]>n/2){
				pair<int,pair<int,int> >pos=q.top();
				q.pop();
				if(vis[pos.second.first]){
					continue;
				}
				else if(cnt[pos.second.second]>n/2){
					continue;
				}
				vis[pos.second.first]=1;
				cnt[pos.second.second]++;
				cnt[wr]--;
				ans-=pos.first;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
} 
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0

