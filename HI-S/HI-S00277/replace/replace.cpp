#include<bits/stdc++.h>
#define ll long long
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fst first
#define snd second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#define int ll

using namespace std;
bool STA_MEMORY;

int n,m,ans,k,q;
const int N=2e5+10,mod=998244353;

pair<string,string> A[N];

int a[N],d[N],b[N];


void solveB(){
	rep(i,1,n+q){
		cin>>A[i].fst>>A[i].snd;
		int b1=-1,b2=-1;
		rep(j,0,A[i].fst.size()) if(A[i].fst[j]=='b') b1=j;
		rep(j,0,A[i].snd.size()) if(A[i].snd[j]=='b') b2=j;
		a[i]=min(b1,b2)-1;
		d[i]=b2-b1;
		b[i]=A[i].fst.size()-max(b1,b2);
	}
	
	rep(j,n+1,n+q){
		rep(i,1,n){
			ans=0;
			if(d[i]==d[j] && a[j]>=a[i] && b[j]>=b[i]) ans++;
			cout<<ans<<'\n';
		}
	}
	
}

void solve(){
	cin>>n>>q;
	
	solveB();
}
bool END_MEMORY;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
//	fastIO;
	
	int c,T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	
	cerr<<"\n\nMemory:  "<<(&END_MEMORY-&STA_MEMORY)/1048576<<"  MB\n";
	return 0;
}

