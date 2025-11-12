#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int T,n;
pair<int,int>a[100001][3];
int Main(){
	cin>>n;
	int ans=0,c[3]={0,0,0};
	priority_queue<tuple<int,int,int>>q;
	for(int i=1;i<=n;++i){
		for(int j=0;j<3;++j)cin>>a[i][j].x,a[i][j].y=j;
		sort(a[i],a[i]+3,greater<>());
		q.emplace(a[i][0].x-a[i][1].x,i,0);
	}for(;!q.empty();){
		auto[v,u,i]=q.top();q.pop();
		if(c[a[u][i].y]<n/2){
			++c[a[u][i].y];
			ans+=a[u][i].x;
		}else{
			if(i+1==2)q.emplace(a[u][i+1].x,u,i+1);
			else q.emplace(a[u][i+1].x-a[u][i+2].x,u,i+1);
		}
	}return ans;
}signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	for(cin>>T;T--;)cout<<Main()<<'\n';
}