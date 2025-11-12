#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt[20],kw[20],tot,ans,mov[20],f[110010],kkw[20][110010];
struct edge{
	int a,b,w;
};
bool operator <(const edge x,const edge y){
	return x.w>y.w;
}
priority_queue<edge,vector<edge> > q;
int getf(int x){
	if(f[x]==x)
		return x;
	return f[x]=getf(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,w;
		cin>>a>>b>>w;
		q.push((edge){a,b,w});
	}
	for(int i=1;i<=k;i++){
		cin>>kw[i];
		int a=n+i,b=1,w;
		for(;b<=n;cin>>w,kkw[i][b]=w,w+=kw[i],q.push((edge){a,b,w}),b++);
	}
	for(int i=1;i<=n+k;f[i]=i,i++);
	for(;tot<n+k-1;){
		edge qq=q.top();
		q.pop();
		int fa=getf(qq.a),fb=getf(qq.b);
		if(fa==fb)
			continue;
		tot++;
		ans+=qq.w;
		f[fa]=fb;
		if(qq.a>n){
			if(!cnt[qq.a-n]){
				mov[qq.a-n]=qq.w;
				for(int i=1;i<=n;q.push((edge){qq.a,i,kkw[qq.a-n][i]}),i++);
			}
			cnt[qq.a-n]++;
		}
	}
	for(int i=1;i<=k;i++)
		if(cnt[i]==1)
			ans-=mov[i];	
	cout<<ans;
	return 0;
} 

