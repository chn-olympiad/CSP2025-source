#include<bits/stdc++.h>
#define rg register int
#define fo(i,l,r) for(rg i=(l);i<=(r);i++)
#define dfo(i,r,l) for(rg i=(r);i>=(l);i--)
#define fe(i,x) for(rg i=hd[x];i;i=nex[i])
#define frein freopen("in.txt","r",stdin)
#define freout freopen("out.txt","w",stdout)
#define fre(p) freopen(#p".in","r",stdin),freopen(#p".out","w",stdout)
#define vi vector<int>
#define eb emplace_back
#define pii pair<int,int>
#define fir first
#define sec second
#define mkp make_pair
#define i8 __int128
#define db double
#define ll long long
using namespace std;
bool deb=1;
void ck_(){cerr<<"\n";}
template<typename T,typename...R>
void ck_(T x,R...y){if(!deb)return;cerr<<x<<" ";ck_(y...);}
void Bz_(){cerr<<"---------------------------------\n";}
#define ck ck_
#define Bz Bz_()
#define outa(l,r,a) {fo(II,l,r)cerr<<a[II]<<" ";cerr<<"\n";}
const int N=1e5+5;ll ans;
int T,n,x,y,z;
struct nd{int x,y;}a[N],b[N],c[N];int la,lb,lc;
void solve()
{
	cin>>n;
	la=lb=lc=0,ans=0;
	fo(i,1,n)
	{
		cin>>x>>y>>z;
		if(x>=y&&x>=z)a[++la]=nd{x,max(y,z)},ans+=x;
		else if(y>=x&&y>=z)b[++lb]=nd{y,max(x,z)},ans+=y;
		else c[++lc]=nd{z,max(x,y)},ans+=z;
	}
	if(lb>n/2)swap(a,b),swap(la,lb);
	if(lc>n/2)swap(a,c),swap(la,lc);
	if(la>n/2)
	{
		sort(a+1,a+1+la,[](nd a,nd b){return a.y-a.x>b.y-b.x;});
		fo(i,1,la-n/2)ans+=a[i].y-a[i].x;
	}
	cout<<ans<<"\n";
}
int main()
{
//	frein;
	fre(club);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)solve();
	return 0;
}
