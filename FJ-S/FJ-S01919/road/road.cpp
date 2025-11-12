#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w,tap;
};
int cmp(node c,node d){
	return c.w>d.w;
}
priority_queue<node,vector<node>,decltype(&cmp)> q(cmp);
int n,m,k,f[20005],ans,l[20005];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	if(f[x]!=f[y]) f[x]=y;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		q.push({a,b,c,0});
	}
	int c;
	for(int i=n+1;i<=k+n;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>l[i];
		}
		for(int j=1;j<=n;j++){
			for(int r=j+1;r<=n;r++){
				q.push({j,r,l[j]+l[r],1});
			}
		}
	}
	int sum=0,s=0;
	while(!q.empty()){
		node cnt=q.top();
		q.pop();
		if(find(cnt.u)!=find(cnt.v)){
			merge(cnt.u,cnt.v);
			ans+=cnt.w;
			sum++;
			if(cnt.tap==1) s=1;
		}
	}
	cout<<ans;
	return 0;
}