#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> PIII;
const int N=2e6+10,K=1e4;
int n,m,k,s[N];
struct node{
	int w,x,y;
};
vector<node> edge[20];
priority_queue<PIII,vector<PIII>,greater<PIII>> qt;
int find(int x){
	if(s[x]!=x) s[x]=find(s[x]);
	return s[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x,y,w;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&w);
		qt.push({w,{x,y}});
	}
	for(int i=1;i<=n;i++) s[i]=i;
	for(int i=1;i<=k;i++){
		scanf("%d",&w);
		qt.push({w,{0,i+K}}); 
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			edge[i].push_back({w,i+K,j});
			s[i+K]=i+K;
		}
	}
	int sum=n+k+1,cnt=0;
	long long ans=0;
	while(!qt.empty()){
		int x=qt.top().second.first;
		int y=qt.top().second.second;
		int w=qt.top().first;
		qt.pop();
		if(!x){
			for(auto j:edge[y-K]) qt.push({j.w,{j.x,j.y}});
			cnt++;
		}else{
			int xx=find(x),yy=find(y);
			if(xx!=yy){
				s[xx]=yy;
				ans+=w;
				sum--;
			}
		}
		if(sum==k-cnt+1) break;
	}
	printf("%lld\n",ans);
	return 0;
}
