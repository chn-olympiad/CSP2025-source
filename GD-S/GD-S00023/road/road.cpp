#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
const int maxn=2e4+10;
const int maxm=2e6+10;
const ll inf=1e18+10;
int f[maxn];
bool st[maxn];
int n,m,tot,k;
ll c[maxn],ans=inf;
struct node{
	int x,y;
	ll w;
	bool operator<(const node&a) const{
		return w<a.w;
	} 
};
node lin[maxm];
int fnd(int x){
	if(x==f[x])
		return f[x];
	else{
		return f[x]=fnd(f[x]);
	}
}
ll read(){
	char ch=getchar();
	ll sum=0;
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=sum*10+(ch-'0');
		ch=getchar();
	}
	return sum;
}
ll fun(int s){
	memset(st,0,sizeof(st));
	ll sum=0;
	int cnt=n;
	for(int i=1;i<=n+k;i++){
		f[i]=i;
		if(i>=1&&i<=n){
			st[i]=1;
		}
	}
	for(int i=n+1;i<=n+k;i++){
		if((s>>(i-(n+1)))&1){
			st[i]=1;
			sum+=c[i];
			cnt++;
		}
	}
	for(int i=1;i<=tot;i++){ 
		int x=lin[i].x;
		int y=lin[i].y;
		if(!st[x]||!st[y])
			continue;
		if(fnd(x)==fnd(y))
			continue;
		x=fnd(x);
		y=fnd(y);
		f[x]=y;
		cnt--;
		sum+=lin[i].w;
		if(cnt==1){
			return sum;
		}
	}
	return inf;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		++tot;
		lin[tot].x=read();
		lin[tot].y=read();
		scanf("%lld",&lin[tot].w);
	}
	for(int i=n+1;i<=n+k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			++tot;
			lin[tot].x=i;
			lin[tot].y=j;
			scanf("%lld",&lin[tot].w); 
		}
	} 
	sort(lin+1,lin+tot+1);
	for(int s=0;s<(1<<k);s++){//激活哪些城市 
		ans=min(ans,fun(s));
	}
	printf("%lld",ans);
	return 0; 
}

