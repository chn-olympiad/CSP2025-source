#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int maxn=100005;
ll t,n,a[maxn][5],f[maxn][5],g[maxn],num[maxn],d[maxn],s[maxn],cnt;
struct stu
{
	ll a,b,c;	
}p[maxn];
inline void fre()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
inline bool cmp(stu a,stu b)
{
	return a.a>a.b;
}
inline void caseA()
{
	ll ans=0;
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=n/2;i++)
	{
		ans+=p[i].a;
	}
	cout<<ans<<endl;
}
inline ll powder(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
inline void fl(ll x)
{
	cnt=0;
	num[0]=num[1]=num[2]=0;
	while(x)
	{
		ll c=x%3;
		num[c]++;
		d[++cnt]=c;
		x/=3; 
	}
	if(cnt<n) 
	{
		ll cntt=cnt;
		for(int i=n-cnt+1;i<=n;i++) 
		{
			s[i]=d[cntt];
			cntt--;
		}
		for(int i=1;i<=n-cnt;i++) 
		{
			s[i]=0;
			num[0]++;
		}
		cnt=n;
	}
	else for(int i=1;i<=cnt;i++) s[i]=d[cnt-i+1];
}
inline void case1()
{
	ll ans=0;
	for(int i=1;i<=powder(3,n)-1;i++)
	{
		ll res=0;
		fl(i);
		if((num[0]>n/2)||(num[1]>n/2)||(num[2]>n/2)) continue;
		for(int j=1;j<=cnt;j++)
		{
			if(!s[j]) res+=p[j].a;
			else if(s[j]==1) res+=p[j].b;
			else res+=p[j].c;
		}
		ans=max(ans,res); 
	}
	cout<<ans<<endl;
}
int main()
{
	IOS
	fre();
	cin>>t;
	while(t--)
	{
		ll flaga=1,flagb=1,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i].a>>p[i].b>>p[i].c;
			a[i][1]=p[i].a;
			a[i][2]=p[i].b;
			a[i][3]=p[i].c;
			if(p[i].b||p[i].c) flaga=0;
			if(p[i].b) flagb=0;
		}
		if(flaga) 
		{
			caseA();
			continue;
		}
		if(n<=10)
		{
			case1();
			continue;
		}
		/*f[1][1]=a[1][1],f[1][2]=a[1][2],f[1][3]=a[1][3];
		for(int i=2;i<=n;i++)
		{
			ll maxx=max(f[i-1][1],max(f[i-1][2],f[i-1][3]));
			if(maxx==f[i-1][1]) g[1]++;
			else if(maxx==f[i-1][2]) g[2]++;
			else g[3]++;
			f[i][1]=maxx+a[i][1];
			f[i][2]=maxx+a[i][2];
			f[i][3]=maxx+a[i][3];
		}	
		/*for(int i=1;i<=n;i++)
		{
			cout<<f[i][1]<<" "<<f[i][2]<<" "<<f[i][3]<<endl;
		}
		if(g[1]>n/2) ans=max(f[n][2],f[n][3]);
		else if(g[2]>n/2) ans=max(f[n][1],f[n][3]);
		else if(g[3]>n/2) ans=max(f[n][1],f[n][2]);
		else ans=max(max(f[n][1],f[n][2]),f[n][3]);
		cout<<ans<<endl;*/
	}
	return 0;
}
