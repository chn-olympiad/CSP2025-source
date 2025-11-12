#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
int read(){
	char c = getchar();
	int a = 0;
	while(c<'0' || c>'9')c = getchar();
	while(c>='0' && c<='9'){
		a = a*10+c-'0';
		c = getchar();
	}
	return a;
}
int n,m,k;
int fa[10020];
int cc[12];
long long ans = 0;
struct bian{
	int u,v,w;
}g[1000010],c[12][10010],kru[110010],tmp[110010];
//__________________________________
int find(int x){
	return x == fa[x] ? x : (fa[x] = find(fa[x]));
}
void hb(int x,int y){
	fa[find(x)] = find(y);
}
//_____________________________________
bool cmp_g(bian a,bian b){
	return a.w<b.w;
}
void re(){
	for(int i = 1;i<=n+12;i++)fa[i] = i;
}
//_______________________________________
void solve(int sum){
	re();
	int tmp = n;
	long long maxn = 0;
	int tot = 1;
	while(sum){
		if(sum&1)tmp++,maxn = maxn + cc[tot];
		sum>>=1;
		tot++;
	}
//	cout<<maxn<<" ";
	int cnt = 0;
//	cout<<m<<" ";
	for(int i = 1;i<=m;i++){
		int u = kru[i].u,v = kru[i].v,w = kru[i].w;
		//cout<<sum<<" ";
		if(find(u) != find(v)){
			hb(u,v);
			cnt++;
			maxn = maxn + w;
			if(cnt == tmp-1){
				ans = min(ans,maxn);
				//cout<<maxn<<" ";
				return ;
			}
		}
	}
//	cout<<sum<<" ";
	//cout<<maxn<<"\n";
}
void add(int num){
	int idx = 0;
	for(int i = 0;i<=10;i++){
		if(num & (1<<i)){
			idx = i+1;
			break;
		}
	}
	m = m+n;
	int tot1 = 1,tot2 = 1;
	for(int i = 1;i<=m;i++){
	//	cout<<i<<" ";
		if((c[idx][tot1].w <= kru[tot2].w && tot1 <= n) || tot2 > m-n){
			tmp[i] = c[idx][tot1];
			tot1++;
		}else{
			tmp[i] = kru[tot2];
			tot2++;
		}
	}
	for(int i = 1;i<=m;i++)kru[i] = tmp[i];
}
void del(int num){
	int idx = 0;
	for(int i = 0;i<=10;i++){
		if(num & (1<<i)){
			idx = i+1;
			break;
		}
	}
	m = m-n;
	int tot = 1;
	for(int i = 1;i<=m;i++){
		while(kru[tot].u == idx+n)tot++;
		kru[i] = kru[tot];
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();
	m = read();
	k = read();
	for(int i = 1;i<=m;i++){
		g[i].u = read();
		g[i].v = read();
		g[i].w = read();
	}
	sort(g+1,g+m+1,cmp_g);
	re();
	int cnt = 0;
	for(int i = 1;i<=m;i++){
		int u = g[i].u,v = g[i].v,w = g[i].w;
		if(find(u) != find(v)){
			hb(u,v);
			kru[++cnt] = {u,v,w};
			ans = ans+w;
			if(cnt == n-1){
				m = n-1;
			}
		}
	}
//	cout<<ans;
	int x;
	for(int i = 1;i<=k;i++){
		cc[i] = read();
		for(int j = 1;j<=n;j++){
			x = read();
			c[i][j] = {i+n,j,x};
		}
		sort(c[i]+1,c[i]+n+1,cmp_g);
	}
	int last = 0;
	for(int i = 1;i<(1<<k);i++){
		int now = i^(i>>1);
		//cout<<now<<" ";
		if(now > last){
			add(now-last);
		}else{
			del(last-now);
		}
		last = now;
		solve(now);
	} 
//	for(int i = 1;i<=k;i++)cout<<cc[i]<<" ";
	cout<<ans;
}
