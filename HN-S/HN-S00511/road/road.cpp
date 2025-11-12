#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k;
struct Node{
	int x,y;
	long long w;
};
vector<Node> v;
int to[N];
int vis[M];
int edge[15];
int a[15][10005];
bool cmp(Node x,Node y){
	return x.w>y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		long long w;
		cin>>x>>y>>w;
		ans+=w;
		v.push_back({x,y,w});
		to[x]++;
		to[y]++;
	}
	if(k==0){
		for(int i=1;i<=k;i++){
		    cin>>edge[i];
	    	for(int j=1;j<=n;j++){
	    		cin>>a[i][j];
	    	}
    	}
    	sort(v.begin(),v.end(),cmp);
    	int cnt=0;
    	for(int i=0;i<m;i++){
	    	if(cnt==m-n+1) break;
	    	int x=v[i].x,y=v[i].y;
	    	long long w=v[i].w;
	    	if(to[x]==1||to[y]==1) continue;
	        ans-=w;
	    	to[x]--;
		    to[y]--;
	    	vis[i]=1;
	    	cnt++;
    	}
	    cout<<ans;
	}else{
		m+=k*n;
		for(int i=1;i<=k;i++){
		    cin>>edge[i];
		    int y=n+i;
	    	for(int j=1;j<=n;j++){
	    		long long w;
	    		cin>>w;
	    		ans+=w;
	    		v.push_back({y,j,w});
	    		to[y]++;
	    		to[j]++;
	    	}
    	}
    	sort(v.begin(),v.end(),cmp);
    	int cnt=0;
    	for(int i=0;i<m;i++){
	    	int x=v[i].x,y=v[i].y;
	    	long long w=v[i].w;
	    	if((to[x]==1&&x<=n)||(to[y]==1&&y<=n)) continue;
	        ans-=w;
	    	to[x]--;
		    to[y]--;
	    	vis[i]=1;
	    	cnt++;
    	}
	    cout<<0;
	}
	return 0;
}
