#include<bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<=m;++i)
#define ref(i,n,m) for(int i=n;i>=m;--i)
#define ll long long
using namespace std;
const int N=5e2+5,mod=998244353;
int c[N],p[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string st;
	int n,m;
	ll res=0;
	cin>>n>>m>>st;
	rep(i,1,n) cin>>c[i];
	rep(i,1,n) p[i]=i;
//	if(n>11){
//		sort(c+1,c+n+1);
//		int s=0;
//		res=1;
//		rep(i,1,n){
//			if(s>=c[i]) ++s;
//			else break;
//		}
//		rep(i,2,n-s) res=res*i%mod;
//		rep(i,2,s){
//			if(c[i]==s[i-1])
//		}
//		return 0;
//	}
	do{
		int k=0,s=0;
		rep(i,1,n){
			if(st[i-1]=='0') ++k;
			else{
				if(k>=c[p[i]]) ++k;
				else ++s;
			}
		}
		if(s>=m){
			++res;
			if(res>=mod) res-=mod;
		}
	}while(next_permutation(p+1,p+n+1));
	cout<<res;
}
