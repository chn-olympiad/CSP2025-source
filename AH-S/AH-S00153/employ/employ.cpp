#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
#define int long long
using namespace std;
const int N=5e2+10,MOD=998244353;
int n,m,tot;
int c[N],s[N],ct0;
int f[2][20][1<<18];
vector<int> e[N];
signed main(){
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	forr(i,1,n){
		char ch;cin>>ch;
		if(ch=='1')c[i]=1;
		else ct0++;
	}
	forr(i,1,n){
		cin>>s[i];
		if(s[i]==0)ct0++;
	}
	if(n==m){
		if(ct0){
			cout<<0<<endl;return 0;
		}
		int ans=1;
		forr(i,1,n)ans=ans*i%MOD;
		cout<<ans<<endl;
		return 0;
	}
	forr(i,1,(1ll<<n)-1){
		e[__builtin_popcountl(i)].push_back(i);
	}
	f[0][0][0]=1;
	forr(i,1,n){
		for(auto j :e[i]){
			forr(k,1,n){
				if(j&(1<<(k-1))){
					forr(l,0,i-1)(f[i&1][l+c[i]*(s[k]>i-1-l)][j]+=f[(i&1)^1][l][j^(1<<(k-1))])%=MOD;
				}
			}
		}
	}
	forr(j,m,n)(tot+=f[n&1][j][(1ll<<n)-1])%=MOD;
	cout<<tot;
	return 0;
}
/*
18 16
111111101011111111
2 3 4 5 6 7 8 9 0 2 3 4 5 6 7 8 6 3
*/
