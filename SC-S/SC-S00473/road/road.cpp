#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;

ll n,m,k,l,ans=10000000000;
ll f[N],b[N],p[20][N],q[N];

struct hhj{
	ll l,r,mon;
}a[N];

bool cmp(hhj x,hhj y){
	return x.mon<y.mon;
}

void query(ll num){
	for(int i=1;i<=num;i++) f[i]=i;
}
ll find(ll x){
	return f[x]=(f[x]==x?x:find(f[x]));
}
void merge(ll x,ll y){
	ll fx=find(x),fy=find(y);
	if(fx==fy) return;
	f[fy]=fx;
}
bool same(ll x,ll y){
	return find(x)==find(y);
}
ll tmp=1;
void read(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].l>>a[i].r>>a[i].mon;
	}
	for(int i=1;i<=k;i++){
		cin>>p[i][0];
		l+=(p[i][0]==0);
		for(int j=1;j<=n;j++){
			cin>>p[i][j];
			a[m+tmp].mon=p[i][j];
			a[tmp+m].l=j;a[tmp+m].r=i+n;
			tmp++;
		}
	}
	sort(a+1,a+1+m+tmp,cmp);
}
ll s1(ll sum,ll num){
	query(m+k);
	ll cnt=0;
	for(int i=1;i<=m+tmp;i++){
		if(!same(a[i].l,a[i].r)){
			if(a[i].r>n&&!b[a[i].r-n]) continue;
			merge(a[i].l,a[i].r);
			cnt+=a[i].mon;
		}
	}
	return sum+cnt;
}
void dfs(ll xb,ll sum,ll num){
	if(xb>k){
		ans=min(ans,s1(sum,num));
		return;
	}
	dfs(xb+1,sum,num);
	b[xb]=1;
	dfs(xb+1,sum+p[xb][0],num+1);
	b[xb]=0;
}
void s2(){
	ans=0;
	query(m+k);
	for(int i=1;i<=m+tmp;i++){
		if(!same(a[i].l,a[i].r)){
			if(a[i].r>n) q[a[i].r-n]++;
			merge(a[i].l,a[i].r);
			ans+=a[i].mon;
		}
	}
	for(int i=1;i<=k;i++){
		if(q[i]==1){
			ll mn=2000000000;
			for(int j=1;j<=n;j++){
				mn=min(mn,p[i][j]);
			}
			ans-=mn;
		}
	}
//	cout<<ans<<'\n'
}
void solve(){
	if(l==k) s2();
	else dfs(1,0,0);
	cout<<ans<<"\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read();solve();
	return 0;
}