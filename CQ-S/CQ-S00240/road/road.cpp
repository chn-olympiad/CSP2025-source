#include<bits/stdc++.h>
using namespace std;
// wei ren min fu wu 
int f[1045],cnt=1;int n,m,k;
unsigned int c[14][1045];
unsigned int cc[1024][1045];
unsigned int a[1045][1045];
unsigned int ma[1045][1045];
unsigned int c_[1045];
unsigned int f_f(int fa){
	if(fa!=f[fa])return f_f(f[fa]);
	return fa;
}
bool ff(unsigned int fa,unsigned int fb){
    f[fa]=f_f(fa);f[fb]=f_f(fb);
    return f[fa]==f[fb];
}
bool slove(int t_){
	if(!t_)return false;
for(int i=1;i<t_;i=i<<1)if(t_&i)if(slove(t_^i))return true;
	for(int i=1;i<=n;i++)if(c_[i]<cc[t_][i])return true;
	return false;
}
int main(){ 
long long ans,ans_=1e17;int tmp_;
	freopen("road1.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)a[i][j]=2147483647;
	int u,v,w;int* _u=&u;int *_v=&v;int *_w=&w; 
	for(int i=0;i<m;i++){
		scanf("%d%d%d",_u,_v,_w);
		a[u][v]=w;a[v][u]=w;
		
	}
	for(int i=0;i<k;i++)for(int j=0;j<=n;j++)scanf("%d",c[i]+j); 
	for(int tmp=0;tmp<(1<<k);tmp++){
	for(int i=1;i<=n;i++)c_[i]=2147483647;	
	ans=0;
		for(int _=0;_<k;_++)if(tmp&_){ans+=c[_][0];
		for(int i=1;i<=n;i++)c_[i]=min(c_[i],c[_][i]);}
	if(!tmp||slove(tmp)){
	for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){ma[i][j]=min(a[i][j],(c_[i]+c_[j]));}
cc[tmp][i]=c_[i];}

	cnt=1;
	for(int i=1;i<n;i++)f[i]=i;
	while(cnt!=n){
		v=2147483647;u=0;
		for(int i=1;i<=n;i++)
		if(ff(1,i)){cout<<v<<' ';
		for(int j=2;j<=n;j++)
		if(a[i][j]<v&&!ff(i,j)){v=a[i][j];u=j;}
		if(u){ans+=v;f[u]=1;}}
		cnt++;
		
	}
	if(ans<ans_)ans_=ans;
	}}printf("%d",ans_);
	return 0;
}
