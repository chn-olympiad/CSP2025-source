#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define dF(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define ll long long
#define uint unsigned
#define ull unsigned long long
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define lowbit(x) ((x)&(-(x)))
using namespace std;
bool ST;
template<typename T>inline void chkmax(T &x,const T y){ x=max(x,y); }
template<typename T>inline void chkmin(T &x,const T y){ x=min(x,y); }
const int inf=1000000005;
const ll infll=1000000000000000005ll;
const int maxn=500005;
void fre(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
}
int n,a[maxn][3],dt[maxn],cnt[3],col[maxn];
void Solve_(){
	cin>>n;
	F(i,1,n)F(j,0,2)cin>>a[i][j];
	int ans=0;
	memset(cnt,0,sizeof cnt);
	F(i,1,n){
		if(a[i][0]>=max(a[i][1],a[i][2]))++cnt[0],dt[i]=a[i][0]-max(a[i][1],a[i][2]),col[i]=0,ans+=a[i][0];
		else if(a[i][1]>=max(a[i][0],a[i][2]))++cnt[1],dt[i]=a[i][1]-max(a[i][0],a[i][2]),col[i]=1,ans+=a[i][1];
		else ++cnt[2],dt[i]=a[i][2]-max(a[i][0],a[i][1]),ans+=a[i][2],col[i]=2;
	}
	int typ=-1,num=0;
	F(i,0,2)if(cnt[i]>(n>>1))typ=i,num=cnt[i]-(n>>1);
	vector<int>vec;
	F(i,1,n)if(col[i]==typ)vec.push_back(dt[i]);
	sort(all(vec));
	F(_,0,num-1)ans-=vec[_];
	cout<<ans<<'\n';
}
bool ED;
signed main(){
	fre(),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int zsy=1;cin>>zsy;
	F(_,1,zsy)Solve_();
}
// g++ club.cpp -o a -std=c++14 -O2