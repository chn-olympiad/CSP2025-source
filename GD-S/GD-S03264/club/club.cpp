#include<bits/stdc++.h>
#define ll long long 
#define ygkg putchar(' ')
#define endl putchar('\n')
const ll inf=1e16;
const ll mod=998244353;
namespace io
{
	template<typename L>
	void in(L &x)
	{
		x=0;bool f=false;char ch=getchar();
		while(!isdigit(ch)) f=ch=='-',ch=getchar();
		do{x=(x<<3)+(x<<1)+(ch^48);}while(isdigit(ch=getchar()));
		if(f) x=-x;
	}
	template<typename L>
	void _out(L x){if(x) _out(x/10),putchar((x%10)^48);}
	template<typename L>
	void out(L x){_out(x>0?x:(x?(putchar('-'),-x):(putchar('0'),0))),endl;}
}
using namespace io;
using namespace std;
ll T;
ll n,a[100015][3],f[100015];
ll sum,w[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	in(T);
	while(T--)
	{
		in(n);
		for(ll i=1;i<=n;++i)
		{
			in(a[i][0]),in(a[i][1]),in(a[i][2]);
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) f[i]=0;
			else if(a[i][1]>=a[i][2]) f[i]=1;
			else f[i]=2;
			++w[f[i]],sum+=a[i][f[i]];
//			cout<<f[i]<<" ";
		}
		priority_queue<ll,vector<ll>,greater<ll>> q;
		if(w[0]>n/2)
		{
			for(ll i=1;i<=n;++i)
				if(f[i]==0)
					q.push(a[i][0]-max(a[i][1],a[i][2]));
			for(ll i=1;i<=w[0]-n/2;++i)
				sum-=q.top(),q.pop();
		}
		if(w[1]>n/2)
		{
			for(ll i=1;i<=n;++i)
				if(f[i]==1)
					q.push(a[i][1]-max(a[i][0],a[i][2]));
			for(ll i=1;i<=w[1]-n/2;++i)
				sum-=q.top(),q.pop();
		}
		if(w[2]>n/2)
		{
			for(ll i=1;i<=n;++i)
				if(f[i]==2)
					q.push(a[i][2]-max(a[i][0],a[i][1]));
			for(ll i=1;i<=w[2]-n/2;++i)
				sum-=q.top(),q.pop();
		}
		out(sum);
		w[0]=w[1]=w[2]=sum=0;
	}
	return 0;
}
