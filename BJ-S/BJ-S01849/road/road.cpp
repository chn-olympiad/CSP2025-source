#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
#define pub push_back
#define all(x) x.begin(),x.end()
#define Cl(x) memset(x,0,sizeof(x))
const int DC=0;
const ll mod=0;
const int N=0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll b,ll p=mod){ll ans=1;for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;return ans;}
const ll inf=0x3f3f3f3f3f3f3f3f;
mt19937 rng(random_device{}());

int n,m,k;
struct nd{int x,y,z;};
vector<nd>e,te;
int sp[15][10005];
struct dsu{
	int f[20005];
	void init(int n){
		for(int i=1;i<=n;i++)f[i]=i;
	}
	int zx(int x){return f[x]==x?x:f[x]=zx(f[x]);}
	void mg(int x,int y){
		if(rng()%2)f[zx(x)]=zx(y);
		else f[zx(y)]=zx(x);
	}
}d;
bool can[10015];
ll gmst(int st){
	for(int i=1;i<=n;i++)can[i]=1;
	ll ans=0;
	for(int i=0;i<k;i++)if(st>>i&1)can[n+i+1]=1,ans+=sp[i+1][0];
	else can[n+i+1]=0;
	d.init(n+k);
	for(auto[x,y,z]:te)if(can[x]&&can[y]&&d.zx(x)!=d.zx(y)){
		d.mg(x,y);
		ans+=z;
	}
	int c=0;
	for(int i=1;i<=n+k;i++)if(can[i])c+=d.f[i]==i;
	if(c>1)return inf;
	// cerr<<st<<" "<<ans<<"\n";
	return ans;
}

void __INIT__(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
void __SOLVE__(){
	cin>>n>>m>>k;
	d.init(n);
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
		e.pub({x,y,z});
	}
	sort(all(e),[&](nd a,nd b){return a.z<b.z;});
	for(auto[x,y,z]:e){
		if(d.zx(x)==d.zx(y))continue;
		te.pub({x,y,z}),d.mg(x,y);
	}
	for(int i=1;i<=k;i++){
		cin>>sp[i][0];
		for(int j=1;j<=n;j++){
			cin>>sp[i][j];
			te.pub({n+i,j,sp[i][j]});
		}
	}
	sort(all(te),[&](nd a,nd b){return a.z<b.z;});
	ll ans=inf;
	for(int i=0;i<(1<<k);i++)ans=min(ans,gmst(i));
	cout<<ans<<"\n";
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	__INIT__();
	int T=0;DC?cin>>T,1:T=1;
	for(int c=1;c<=T;c++)__SOLVE__();
	return 0;
}