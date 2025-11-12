#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
inline int read(){
	int f=1,s=0;
	char t=getchar();
	while(t<'0'||t>'9'){
		if(t=='-'){
			f=-1;
		}
		t=getchar();
	}
	while(t>='0'&&t<='9'){
		s=s*10+t-'0';
		t=getchar();
	}
	return f*s;
}
const int N=1e5+10;
int t,n;
struct node{
	int index,dt;
};
struct cnp{
	bool operator()(node a,node b){
		a.dt>b.dt;
	}
};
vector<node> a[N];
bool cmp(node a,node b){
	return a.dt>b.dt;
}
inline void solve(){
	priority_queue<node,vector<node>,cnp> club[3];
	n=read();
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=read(),y=read(),z=read();
		a[i].push_back({0,x});
		a[i].push_back({1,y});
		a[i].push_back({2,z});
		sort(a[i].begin(),a[i].end(),cmp);
	}
	for(int i=1;i<=n;i++){
		if(club[a[i][0].index].size()<n/2){
			ans+=a[i][0].dt;
			club[a[i][0].index].push({i,a[i][0].dt});
		}else{
			int q=club[a[i][0].index].top().index;
			int ind;
			/*club[a[i][0].index].pop();
			ans-=a[q][0].dt;
			club[a[q][1].index].push({q,a[q][1].dt});
			ans+=a[q][1].dt;
			club[a[i][0].index].push({i,a[i][0].dt});
			ans+=a[i][0].dt;*/
			if(a[q][0].index==a[i][0].index){
				ind=0;
			}else if(a[q][1].index==a[i][0].index){
				ind=1;
			}else{
				club[a[i][1].index].push({i,a[i][1].dt});
				ans+=a[i][1].dt;
				continue;
			}
			if(club[a[i][0].index].top().dt<a[i][0].dt+a[q][ind+1].dt){
				club[a[i][0].index].pop();
				ans-=a[q][ind].dt;
				club[a[q][ind+1].index].push({q,a[q][ind+1].dt});
				ans+=a[q][ind+1].dt;
				club[a[i][0].index].push({i,a[i][0].dt});
				ans+=a[i][0].dt;
			}else{
				club[a[i][1].index].push({i,a[i][1].dt});
				ans+=a[i][1].dt;
			}
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		a[i].erase(a[i].begin(),a[i].end());
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		solve();
	}
	return 0;
}
