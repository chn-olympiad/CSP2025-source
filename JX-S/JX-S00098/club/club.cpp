#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(a,b,c) for(int a=b;a<=c;++a)
#define dep(a,b,c) for(int a=b;a>=c;--a)
const int N = 1e5+7; const int mod = 1e9+7;
int a[N][4],t[5];
int n,T,ans=0,re=0;
struct node { int cha,Fir,Sec; }f[N];
inline int Check()//O(n)
{
	t[1]=0; t[2]=0; t[3]=0;
	rep(i,1,n)
	{
		int maxx=max(a[i][1], max(a[i][2],a[i][3]) );
		ans=ans+maxx;
		if(a[i][1]==maxx&&a[i][2]==maxx) continue;
		if(a[i][1]==maxx&&a[i][3]==maxx) continue;
		if(a[i][2]==maxx&&a[i][3]==maxx) continue;
		rep(j,1,3) if(a[i][j]==maxx) { t[j]++; break; }
	}
	rep(i,1,3) if(t[i]>n/2) return i;
	return 0;
}
inline bool cmp(node x,node y) { return x.cha>y.cha; }
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		/* .clear. */
		cin>>n;
		rep(i,1,n) rep(j,1,3) cin>>a[i][j]; re=Check();
		if(re==0) { cout<<ans<<endl; continue; } ans=0;
		if(re!=1) rep(i,1,n) swap(a[i][1],a[i][re]);
		rep(i,1,n) f[i].Sec=max(a[i][2],a[i][3]);
		rep(i,1,n) { f[i].Fir=a[i][1]; f[i].cha=f[i].Fir-f[i].Sec; }
		sort(f+1,f+n+1,cmp);
		rep(i,1,n/2) ans=ans+f[i].Fir;
		rep(i,n/2+1,n) ans=ans+f[i].Sec;
		cout<<ans<<endl;
	}
	return 0;
}
