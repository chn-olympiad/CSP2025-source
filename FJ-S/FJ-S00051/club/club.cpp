#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int inf=3e4+1;
int t,n;
int flag[maxn],sum[maxn],ans[maxn],vis[maxn];
pair<int,int> a[maxn][4],maxx[maxn],minn[maxn],mid[maxn];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > > >q;
bool cmp(pair<int,int> aa,pair<int,int> bb){
	return aa.first>bb.first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(maxx,0,sizeof(maxx));
		memset(mid,0,sizeof(mid));
		memset(minn,inf,sizeof(minn));
		memset(sum,0,sizeof(sum));
		memset(ans,0,sizeof(ans)); 
		memset(flag,0,sizeof(flag)); 
		cin>>n;
		int val=n/2;
		for(int i=1;i<=n;++i){
			cin>>a[i][1].first>>a[i][2].first>>a[i][3].first;
			a[i][1].second=1;
			a[i][2].second=2;
			a[i][3].second=3;
		} 
		for(int i=1;i<=n;++i){
			memset(vis,0,sizeof(vis));
			for(int j=1;j<=3;++j){
				if(a[i][j].first>maxx[i].first){
					maxx[i].first=a[i][j].first;
					maxx[i].second=j;
				}
				if(a[i][j].first<minn[i].first){
					minn[i].first=a[i][j].first;
					minn[i].second=j;
				}
			}
			vis[maxx[i].second]=1;
			vis[minn[i].second]=1;
			for(int j=1;j<=3;++j){
				if(!vis[j]){
					mid[i].first=a[i][j].first;
					mid[i].second=j;
				}
			}
		}
		for(int i=1;i<=n;++i){
			q.push({maxx[i].first,{maxx[i].second,i}});
		}
		while(!q.empty()){
			int num=q.top().first,head=q.top().second.first,i=q.top().second.second;
			q.pop();
			//cout<<i<<endl;
			if(mid[i].first==0&&minn[i].first==0){
				if(flag[i])continue;
				flag[i]=1;
				if(sum[head]>=val){
					continue;
				}
				ans[head]+=num;
				sum[head]++;
				//cout<<num<<endl;
			}
			else if(minn[i].first==0){
				if(flag[i])continue;
				flag[i]=1;
				if(sum[head]>=val){
					ans[mid[i].second]+=mid[i].first;
					sum[mid[i].second]++;
					continue;
				}
				ans[head]+=num;
				sum[head]++;
			}
		}
		//for(int i=1;i<=n;++i){
			//cout<<flag[i]<<" ";
		//}
		//cout<<endl;
		for(int i=1;i<=n;++i){
			q.push({maxx[i].first,{maxx[i].second,i}});
		}
		while(!q.empty()){ 
			int i=q.top().second.second;
			q.pop();
			if(flag[i])continue;
			flag[i]=1;
			if(sum[maxx[i].second]<val){
				ans[maxx[i].second]+=maxx[i].first;
				sum[maxx[i].second]++;
				//cout<<maxx[i].first<<endl;
			}
			else if(sum[mid[i].second]<val){
				ans[mid[i].second]+=mid[i].first;
				sum[mid[i].second]++;
				//cout<<mid[i].first<<endl;
			}
			else{
				ans[minn[i].second]+=minn[i].first;
				sum[minn[i].second]++;
				//cout<<minn[i].first<<endl;
			}
		}
		int trueans=ans[1]+ans[2]+ans[3];
		cout<<trueans<<endl;
	}
	return 0;
}
