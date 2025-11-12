#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,M=1e6+5,inf=1e18;
struct Point{
	int u,v,w;
}a[M],b[N],e[15][N];
int n,cnt,m,K,c[15][N],pos[N],f[N],ans,len,d[N];
int getf(int u){
	if(f[u]==u)return u;
	return f[u]=getf(f[u]);	
}
bool cmp(Point x,Point y){
	return x.w<y.w;
}int sum;
void add(Point num){
	int x=getf(num.u),y=getf(num.v);
	if(x==y)return;
	f[x]=y,sum+=num.w;cnt++;
}int L[N];
void work(int S){cnt=0;
	sum=0;int len1=0;pos[++len1]=0;
	for(int i = 1;i <= n+K;i++)f[i]=i;
	for(int i = 0;i < K;i++){
		if(S&(1<<i)){
			sum+=d[i+1];
			pos[++len1]=i+1;
		}
	}
	for(int i = 1;i <= len1;i++)L[i]=1;
	while(1){
		int id=0,val=inf;
		for(int i = 1;i <= len1;i++){
			if(L[i]>n)continue;
			if(val>e[pos[i]][L[i]].w)val=e[pos[i]][L[i]].w,id=i;
		}
		if(!id)break;
		if(ans<=sum)return;
		add(e[pos[id]][L[id]]),L[id]++;
	}
	ans=min(ans,sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> K;for(int i = 1;i <= n;i++)f[i]=i;
	for(int i = 1;i <= m;i++)cin >> a[i].u >> a[i].v >> a[i].w;sort(a+1,a+1+m,cmp);
	for(int i = 1;i <= m;i++){
		int x=getf(a[i].u),y=getf(a[i].v);
		if(x==y)continue;
		ans+=a[i].w,f[x]=y;e[0][++len]=a[i];
	} e[0][++len]=(Point){1,n,inf};
	for(int i = 1;i <= K;i++){
		cin >> d[i];len=0;
		for(int j = 1;j <= n;j++){
			cin >> c[i][j];
			e[i][++len]=(Point){n+i,j,c[i][j]};
		}
		sort(e[i]+1,e[i]+1+len,cmp);
	}
	if(!K){
		cout << ans;
		return 0;
	}//cout << "原图:" << ans << "\n";
	for(int i = 1;i < (1<<K);i++)work(i);
	cout << ans;
	return 0;
}
//神秘
//我就说k不能很大
//嗯，对原图做一个mst
//然后暴力枚举K的状态S(钦定必须使用)
//然后直接大力mst
//O(nlogm+2^KnKlogn)
//1000*10000*10*14
//很有前途!狂砍80tps
//就这么愉快的决定了
//时间复杂度O(2^K*Kn+2^Kn),666预处理得了mvp 
//不是大洋里4跑了0.09s，强度可想而知 
//但是3跑了0.4s,应该不错 
