#include <bits/stdc++.h>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
using namespace std;
const int N=1e5+20;
const int M=4;
int T,n,mx;
//int a[N][4];
priority_queue<pii> pq[M];    //first是值，second是b的club编号 
pair<pii,pii> p[N];
long long ans;
int cnt[M];

void clear(){
	ans=0;
	for(int i=1;i<=3;i++) while(pq[i].size()) pq[i].pop();
	memset(cnt,0,sizeof(cnt));
	mx=n>>1;
}

bool cmp(pii a,pii b){
	return a.first>b.first;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		clear();
		for(int i=1;i<=n;i++){
			vector<pii> v;
			for(int j=1;j<=3;j++){
				pii t;
				cin>>t.first;t.second=j;
				v.push_back(t);
			}
			sort(v.begin(),v.end(),cmp);
			p[i].first.first=v[0].first;p[i].first.second=v[0].second;
			p[i].second.first=v[1].first;p[i].second.second=v[1].second;
		}
		for(int i=1;i<=n;i++){
			pii c=p[i].first,d=p[i].second;
			if(cnt[c.second]==mx){
				pii t=pq[c.second].top();pq[c.second].pop();
//				cout<<"t.first="<<t.first<<endl;
				if(t.first+c.first>d.first){
					ans+=t.first+c.first;
					pq[c.second].push({d.first-c.first,d.second});
					cnt[t.second]++;
				}else{
					ans+=d.first;
					cnt[d.second]++;
				}
			}else{
				cnt[c.second]++;
				ans+=c.first;
				pq[c.second].push({d.first-c.first,d.second});
			}
//			cout<<"ans="<<ans<<endl;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
