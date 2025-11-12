#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define i128 __int128
#define _rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define _per(i,a,b) for(ll i=(a);i>=(b);i--)
#define ckmax(a,b) a=max((ll)(a),(ll)(b))
#define ckmin(a,b) a=min((ll)(a),(ll)(b))
#define PII pair<int,int>
#define fi first
#define se second
#define _add(x,y) x=(((ll)(x)+(y))%mod+mod)%mod
#define _mul(x,y) x=(((ll)(x)*(y))%mod+mod)%mod
#define dbg(x) cout<<#x<<'='<<x<<'\n'
#define ptc putchar

ll rd(){
	ll res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*f;
}
void wr(ll x){
	if(x<0) x=-x,ptc('-');
	if(x>9) wr(x/10);
	ptc(x%10+'0');
}

const int N=1e5+10;

int T=1;
int n,ans;
int a[N][3];
vector<PII> b[3];

void sol(){
	ans=0;
	_rep(j,0,2) b[j].clear();
	
	n=rd();
	_rep(i,1,n) _rep(j,0,2) a[i][j]=rd();
	_rep(i,1,n){
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			b[0].push_back({a[i][0]-max(a[i][1],a[i][2]),i});
			continue;
		}
		if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
			b[1].push_back({a[i][1]-max(a[i][0],a[i][2]),i});
			continue;
		}
		if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]){
			b[2].push_back({a[i][2]-max(a[i][0],a[i][1]),i});
			continue;
		}
	}
	_rep(j,0,2){
		sort(b[j].begin(),b[j].end());
		for(auto x:b[j]) ans+=a[x.se][j];
		if((int)b[j].size()>n/2) _rep(qwq,0,(int)b[j].size()-n/2-1) ans-=b[j][qwq].fi;
	}
	wr(ans),ptc('\n');
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=rd();
	while(T--) sol();
	return 0;
}
