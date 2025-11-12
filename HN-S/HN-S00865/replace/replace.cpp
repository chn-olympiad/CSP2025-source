#include<bits/stdc++.h>
using namespace std;
#define f(n,m,i) for(int i(n);i<=m;++i)
#define nf(n,m,i) for(int i(n);i>=m;--i)
#define dbug(x) cerr<<#x<<':'<<x<<' ';
#define ent cerr<<'\n';
using ll=long long;
using ull=unsigned long long;
ll min(ll x,ll y){  return x<y?x:y;}
ll max(ll x,ll y){  return x<y?y:x;}
ll gcd(ll a,ll b){  return b?gcd(b,a%b):a;}
void swp(ll &x,ll &y){  x^=y^=x^=y;}
const ull bs(131);
const int N(200005),V(5000005);
map<ull,int>mp;
ll n,q,len,l,r,cnt,id,l1,l2;
ull val,vp,vs,hp[V],hs[V];
string u,t;
vector<ull>p[N],s[N];
vector<ll>lp[N],ls[N];
int main(){
	cout.tie(0),cin.tie(0)->sync_with_stdio(0);
	#ifndef MYDEBUG
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	#endif
	cin>>n>>q;
	f(1,n,i){
		cin>>u>>t,len=u.length(),u=" "+u,t=" "+t,vp=vs=val=0;
		if(u==t)	continue;
		f(1,len,j){
			if(u[j]!=t[j]){
				l=j;
				nf(j-1,1,k)	vp=vp*bs+u[k];
				break;
			}
		}
		nf(len,1,j){
			if(u[j]!=t[j]){
				r=j;
				f(j+1,len,k)	vs=vs*bs+u[k];
				break;
			}
		}
		f(l,r,j)	val=val*bs*bs+u[j]*bs+t[j];
		if(mp.count(val))	id=mp[val];
		else	mp[val]=++cnt,id=cnt;
		p[id].push_back(vp),s[id].push_back(vs);
		lp[id].push_back(l-1),ls[id].push_back(len-r);
	}
	f(1,q,i){
		cin>>u>>t,len=u.length(),u=" "+u,t=" "+t,val=0;
		f(1,len,j)	if(u[j]!=t[j]){
			l=j,l1=j-1;
			nf(j-1,1,k)	hp[j-k]=hp[j-k-1]*bs+u[k];
			break;
		}
		nf(len,1,j)	if(u[j]!=t[j]){
			r=j,l2=len-r;
			f(j+1,len,k)	hs[k-j]=hs[k-j-1]*bs+u[k];
			break;
		}
		f(l,r,j)	val=val*bs*bs+u[j]*bs+t[j];
		if(mp.count(val)){
			id=mp[val];ll res(0);
			f(0,p[id].size()-1,j)	if(lp[id][j]<=l1&&ls[id][j]<=l2)
				if(hp[lp[id][j]]==p[id][j]&&hs[ls[id][j]]==s[id][j])
					++res;
			cout<<res<<'\n';
		}
		else	cout<<"0\n";
	}
	return 0;
}
/*
ulimit -s 1000000
g++ -O2 -std=c++14 -static replace.cpp -o replace
./replace
g++ -O2 -std=c++14 -static -Wall -Wextra -Wshadow -Wconversion -DMYDEBUG replace.cpp -o replace && echo ok
./replace

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/