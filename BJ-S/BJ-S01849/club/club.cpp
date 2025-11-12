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
const int DC=1;
const ll mod=0;
const int N=0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll b,ll p=mod){ll ans=1;for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;return ans;}
const ll inf=0x3f3f3f3f3f3f3f3f;

int n;
int a[100005][3],c[3];
priority_queue<int>q[3];

void __INIT__(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
void __SOLVE__(){
	cin>>n;
	for(int x=0;x<3;x++)while(q[x].size())q[x].pop();
	c[0]=c[1]=c[2]=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		int mx=max({a[i][0],a[i][1],a[i][2]});
		ans+=mx;
		if(mx==a[i][0]){
			++c[0];
			q[0].push(max(a[i][1],a[i][2])-a[i][0]);
		}else if(mx==a[i][1]){
			++c[1];
			q[1].push(max(a[i][0],a[i][2])-a[i][1]);
		}else{
			++c[2];
			q[2].push(max(a[i][0],a[i][1])-a[i][2]);
		}
	}
	while(c[0]>n/2)ans+=q[0].top(),q[0].pop(),c[0]--;
	while(c[1]>n/2)ans+=q[1].top(),q[1].pop(),c[1]--;
	while(c[2]>n/2)ans+=q[2].top(),q[2].pop(),c[2]--;
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	__INIT__();
	int T=0;DC?cin>>T,1:T=1;
	for(int c=1;c<=T;c++)__SOLVE__();
	return 0;
}