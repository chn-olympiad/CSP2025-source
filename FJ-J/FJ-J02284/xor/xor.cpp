//I Love CCF
//Accepted!
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define down(i,x,y) for(int i=(x);i>=(y);--i)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
using namespace std;
struct range{
	int l,r;
	range(int a,int b):l(a),r(b){}
	bool operator<(const range& y)const{return r<y.r;}
};
int n,m;
ll s[500005];
int idx[2000006];
vector<range> b;
int f[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(idx,-1,sizeof(idx));
	idx[0]=0;
	rep(i,1,n){
		ll x;
		scanf("%lld",&x);
		s[i]=s[i-1]^x;
		if(idx[s[i]^m]!=-1){
			b.eb(idx[s[i]^m]+1,i);
		}
		idx[s[i]]=i;
	}
	sort(b.begin(),b.end());
	rep(i,0,(int)b.size()-1){
		f[i]=f[i-1];
		int x=lower_bound(b.begin(),b.end(),range(0,b[i].l))-b.begin();
		if(x==0)f[i]=max(f[i],1);
		else{
			--x;
			f[i]=max(f[i],f[x]+1);
		}
	}
	printf("%d\n",f[(int)b.size()-1]);
	return 0;
}
// Can you give me more strong pretests?????

// 你说得对，但是
// I Love CCF. 
