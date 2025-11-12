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
const ll N(100005);
ll t,n,a[N][3],cnt[3],s[3][N],res,id;
int main(){
	cout.tie(0),cin.tie(0)->sync_with_stdio(0);
	#ifndef MYDEBUG
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	#endif
	cin>>t;
	while(t--){
		cin>>n,res=id=cnt[0]=cnt[1]=cnt[2]=0;
		f(1,n,i){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>=max(a[i][1],a[i][2]))
				s[0][++cnt[0]]=a[i][0]-max(a[i][1],a[i][2]),res+=a[i][0];
			else if(a[i][1]>=max(a[i][0],a[i][2]))
				s[1][++cnt[1]]=a[i][1]-max(a[i][0],a[i][2]),res+=a[i][1];
			else	s[2][++cnt[2]]=a[i][2]-max(a[i][1],a[i][0]),res+=a[i][2];
		}
		if(max(cnt[0],max(cnt[1],cnt[2]))<=n/2){
			cout<<res<<'\n';
			continue;
		}
		if(cnt[0]>max(cnt[1],cnt[2]))	id=0;
		else if(cnt[1]>max(cnt[0],cnt[2]))	id=1;
		else	id=2;
		sort(s[id]+1,s[id]+cnt[id]+1);
		ll ul(cnt[id]-n/2);
		f(1,ul,i)	res-=s[id][i];
		cout<<res<<'\n';
	}
	return 0;
}
/*
ulimit -s 1000000
g++ -O2 -std=c++14 -static club.cpp -o club
./club
g++ -O2 -std=c++14 -static -Wall -Wextra -Wshadow -Wconversion -DMYDEBUG club.cpp -o club && echo ok
./club

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/