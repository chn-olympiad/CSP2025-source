//ÎÄ¼þ¶ÁÐ´ 
#include <bits/stdc++.h>
#define N 100010
#define int long long
using namespace std;
int sum=0;
struct node{
	int id,idx;
};
int a[5][N];
vector<node> p[5];
priority_queue<int> pq;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int T;cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			int mx=max({a[1][i],a[2][i],a[3][i]});
			if(mx==a[1][i]) p[1].push_back({1,i});
			else if(mx==a[2][i]) p[2].push_back({2,i});
			else p[3].push_back({3,i});
			sum+=mx;
		}
		int id=0,siz=0;
		if((int)p[1].size()>n/2){
			id=1;siz=p[1].size();
		}
		else if((int)p[2].size()>n/2){
			id=2;siz=p[2].size();
		}
		else if((int)p[3].size()>n/2){
			id=3;siz=p[3].size();
		}
		
		if(id!=0){
			for(auto x:p[id]){
				int idx=x.idx;
				int t=x.id;
				if(t==1){
					pq.push(max(a[2][idx],a[3][idx])-a[1][idx]); 
				}
				else if(t==2){
					pq.push(max(a[1][idx],a[3][idx])-a[2][idx]); 
				}
				else if(t==3) pq.push(max(a[2][idx],a[1][idx])-a[3][idx]); 
			}
		}
		
		for(int i=siz;i>n/2;i--){
			sum+=pq.top();
			pq.pop();
		}
		cout<<sum<<'\n';
		sum=0;
		p[1].clear();p[2].clear();p[3].clear();
		while(!pq.empty()) pq.pop();
	}
	return 0;
}
