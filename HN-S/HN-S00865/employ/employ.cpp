#include<bits/stdc++.h>
using namespace std;
#define f(n,m,i) for(int i(n);i<=m;++i)
#define nf(n,m,i) for(int i(n);i>=m;--i)
#define dbug(x) cerr<<#x<<':'<<x<<' ';
#define ent cerr<<'\n';
using ll=long long;
ll min(ll x,ll y){  return x<y?x:y;}
ll max(ll x,ll y){  return x<y?y:x;}
ll gcd(ll a,ll b){  return b?gcd(b,a%b):a;}
void swp(ll &x,ll &y){  x^=y^=x^=y;}
const ll N(505),p(998244353);
ll n,m,c[N],res(0);
bool vs[N];
string s;
void dfs(int x,int fl){
	if(fl>n-m)	return;
	if(x>n)	return ++res,void();
	f(1,n,i){
		if(!vs[i]){
			vs[i]=1;
			if(s[x]=='0'||fl>=c[i])	dfs(x+1,fl+1);
			else	dfs(x+1,fl);
			vs[i]=0;
		}
	}
}
int main(){
	cout.tie(0),cin.tie(0)->sync_with_stdio(0);
	#ifndef MYDEBUG
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	#endif
	cin>>n>>m>>s,s=" "+s;
	f(1,n,i)	cin>>c[i];
	sort(c+1,c+n+1);
	if(m==n){
		f(1,n,i)	if(s[i]=='0')	return cout<<"0\n",0;
		f(1,n,i)	if(c[i]==0)	return cout<<"0\n",0;
		res=1;
		f(1,n,i)	res=res*i%p;
		return cout<<res<<'\n',0;
	}
	if(n<=18){
		dfs(1,0);
		cout<<res%p<<'\n';
		return 0;
	}
	res=1;
	f(1,n,i)	res=res*i%p;
	cout<<res<<'\n';
	return 0;
}
/*
ulimit -s 1000000
g++ -O2 -std=c++14 -static employ.cpp -o employ
./employ
g++ -O2 -std=c++14 -static -Wall -Wextra -Wshadow -Wconversion -DMYDEBUG employ.cpp -o employ && echo ok
./employ

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/