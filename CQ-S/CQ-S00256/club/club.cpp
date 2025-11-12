#include <bits/stdc++.h>
using namespace std;
#define maxn 201000
int t,n,a[maxn][5],ma[maxn],ans,sema[maxn];
priority_queue<pair<int,int> >q;
vector<int> g[5];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//freopen("club5.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		while(q.size())q.pop();
		g[1].clear();
		g[2].clear();
		g[3].clear();
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			q.push(make_pair(a[i][1],1));
			q.push(make_pair(a[i][2],2));
			q.push(make_pair(a[i][3],3));
			ma[i]=q.top().second;
			q.pop();
			sema[i]=q.top().second;
			while(q.size())q.pop();
			//cout<<sema[i]<<'\n';
		}
		for(int i=1;i<=n;i++){
			ans+=a[i][ma[i]];
			g[ma[i]].push_back(i);
		}
		int lim=0,whi=0;
		for(int i=1;i<=3;i++){
			if(g[i].size()>lim){
				lim=g[i].size();
				whi=i;
			}
		}
//	cout<<whi<<" "<<lim<<'\n';
		if(lim>(n/2)){
			for(int i=0;i<g[whi].size();i++){
				q.push(make_pair(a[g[whi][i]][sema[g[whi][i]]]-a[g[whi][i]][ma[g[whi][i]]],i));
			}
			while(lim>(n/2)&&q.size()){
				//printf("%d %d\n",q.top().first,q.top().second);
				ans+=q.top().first;
				lim--;
				q.pop();
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

