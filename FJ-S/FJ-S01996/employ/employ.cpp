// I Love CCF
// CSP-S 1=
// CSP-S 1=
// CSP-S 1=
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mkp make_pair
#define pll pair<ll,ll>
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define down(i,x,y) for(int i=(x);i>=(y);--i)
#define mod 998244353
using namespace std;
int n,m;
char s[505];
int a[505];
int b[505];
ll ans=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	rep(i,1,n){
		scanf("%d",a+i);
		b[i]=i;
	}
	do{
		int cnt=0,sum=0;
		rep(i,1,n){
			if(sum>=a[b[i]]){
				++sum;continue;
			}
			if(s[i]=='0'){
				++sum;continue;
			}
			if(s[i]=='1')++cnt;
		}
		if(cnt>=m)++ans;
	}while(next_permutation(b+1,b+n+1));
	printf("%lld\n",ans);
	return 0;
}
// I Love CCF
