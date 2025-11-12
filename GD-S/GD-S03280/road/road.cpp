#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=2e6+5;
struct edge{
	int from,to,w;
	bool operator<(const edge& p) const{return w<p.w;}
}a[maxn];
int f[maxn];
int find(int x) {return x==f[x]?x:f[x]=find(f[x]);}
void merge(int x,int y) {f[find(y)]=x;}
int u1[maxn],u2[maxn];
int n,m,k;
map<int,int> dict;
int main(){ 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++) scanf("%d%d%d",&a[i].from,&a[i].to,&a[i].w);
	int cnt1=m,cnt2=n;
	for (int i=1;i<=k;i++){
		cnt2++;
		scanf("%d",&u1[cnt2]);
		int mn=2e9;
		for (int j=1;j<=n;j++){
			cnt1++;
			a[cnt1].from=cnt2;
			a[cnt1].to=j;
			scanf("%d",&a[cnt1].w);
			a[cnt1].w+=u1[cnt2];
			mn=min(mn,a[cnt1].w);
		}
		u2[cnt2]=mn;
	}
	for (int i=1;i<=cnt2;i++) f[i]=i;
	sort(a+1,a+cnt1+1);
	ll ans=0;
	set<int> s;
	for (int i=1;i<=cnt1;i++){
		if (s.size()==n) break;
		if (find(a[i].from)!=find(a[i].to)) {
			merge(a[i].from,a[i].to);
			ans+=a[i].w;
			if (a[i].from<=n) s.insert(a[i].from);
			else dict[a[i].from]++;
			if (a[i].to<=n) s.insert(a[i].to);
			else dict[a[i].to]++;
		}
	}
	for (int i=n+1;i<=cnt2;i++){
		if (dict[i]>=2) ans-=(dict[i]-1)*u1[i];
		else if (dict[i]==1) ans-=u2[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
