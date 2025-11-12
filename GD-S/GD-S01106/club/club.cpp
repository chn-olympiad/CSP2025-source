#include <bits/stdc++.h>
using namespace std;
const int N=1e5+8;
int n,sum=0,link[N];
struct node{int id,x;} p[N][5];
bool cmp(node nx,node mx){return nx.x>mx.x;}
priority_queue <pair<int,int> > sta[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin >>T;
	while (T--){
		cin >>n;sum=0;
		for (int i=1;i<=3;++i) while (!sta[i].empty()) sta[i].pop();
		for (int i=1,x,y,z,op1,op2;i<=n;++i){
			cin >>x>>y>>z;
			p[i][1].x=x,p[i][2].x=y,p[i][3].x=z;
			p[i][1].id=1,p[i][2].id=2,p[i][3].id=3;
			sort(p[i]+1,p[i]+4,cmp);
			link[i]=1;
			sta[p[i][1].id].push({p[i][2].x-p[i][1].x,i});
			sum+=p[i][1].x;
		}
		for (int i=1;i<=3;++i){
			while (sta[i].size()>n/2){
				pair<int,int> u=sta[i].top();sta[i].pop();
				sum+=u.first;
				link[u.second]++;
				sta[p[u.second][link[u.second]].id].push({p[u.second][link[u.second]+1].x-p[u.second][link[u.second]].x,u.second});
			}
		}
		cout <<sum<<'\n';
	}
	return 0;
}
