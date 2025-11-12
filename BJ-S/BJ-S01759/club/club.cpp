#include <bits/stdc++.h>
using namespace std;

struct man
{
	int a[4];
	man() { memset(a,0,sizeof a); }
	int operator[](const int& x) const { return a[x]; }
}a[100100];
istream& operator>>(istream& in,man& x)
{ return in>>x.a[1]>>x.a[2]>>x.a[3]; }
bool cmp1(man x,man y)
{ return x[1]>y[1]; }
bool cmp2(man x,man y)
{ return x[1]>x[2] && x[2]>y[2]; }
bool cmp3(man x,man y)
{ return max(x[1],max(x[2],x[3]))>max(y[1],max(y[2],y[3])); }

int n;

namespace BF
{
	long long f[220][220][220];
	long long n3all()
	{
		memset(f,0,sizeof f);
		for(int i=1;i<=n;++i)
		{
			for(int a1=0;a1<=n;++a1)
			{
				for(int a2=0;a2<=n;++a2)
				{
					if(a1>0) f[i][a1][a2]=f[i-1][a1-1][a2]+a[i][1];
					if(a2>0) f[i][a1][a2]=max(f[i][a1][a2],f[i-1][a1][a2-1]+a[i][2]);
					f[i][a1][a2]=max(f[i][a1][a2],f[i-1][a1][a2]+a[i][3]);
				}
			}
		}
		long long ret=0;
		for(int a1=0;a1<=n/2;++a1)
		{
			for(int a2=0;a2<=n/2;++a2)
			{
				int a3=n-a1-a2;
				if(a3>n/2) continue;
				ret=max(ret,f[n][a1][a2]);
			}
		}
		return ret;
	}
	long long spc_A()
	{
		sort(a+1,a+n+1,cmp1);
		long long ret=0;
		for(int i=1;i<=n/2;++i) ret+=a[i][1];
		return ret;
	}
	long long spc_B()
	{
		sort(a+1,a+n+1,cmp2);
		long long ret=0;
		for(int i=1;i<=n/2;++i)
			ret+=a[i][2];
		for(int i=n/2+1;i<=n;++i)
			ret+=a[i][1];
		return ret;
	}
	void add(int& a,int& b,int& c)
	{
		int mn=min(min(a,b),c);
		if(mn==a) a++;
		else if(mn==b) b++;
		else c++;
	}
	int cnt1=0,cnt2=0,cnt3=0, tmp=1000000000;
	bool act(int mx,int i)
	{
		if(a[i][1]==mx)
		{
			if(a[i][2]==mx)
			{
				if(a[i][3]==mx) add(cnt1,cnt2,cnt3);
				else add(cnt1,cnt2,tmp);
			}
			else if(a[i][3]==mx)
			{
				add(cnt1,cnt3,tmp);
			}
			else
			{
				cnt1++;
			}
		}
		else if(a[i][2]==mx)
		{
			if(a[i][3]==mx) add(cnt2,cnt3,tmp);
			else cnt1++;
		}
		else
		{
			cnt3++;
		}
		if(cnt1>n/2)
		{
			cnt1--;
			return 0;
		}
		if(cnt2>n/2)
		{
			cnt2--;
			return 0;
		}
		if(cnt3>n/2)
		{
			cnt3--;
			return 0;
		}
		return 1;
	}
	long long greedy()
	{
		sort(a+1,a+n+1,cmp3);
		long long ret=0;
		for(int i=1;i<=n;++i)
		{
			int mx=max(a[i][1],max(a[i][2],a[i][3])), mn=min(a[i][1],min(a[i][2],a[i][3])), md=a[i][1]+a[i][2]+a[i][3]-mx-mn;
			if(act(mx,i)) ret+=mx;
			else if(act(md,i)) ret+=md;
			else if(act(mn,i)) ret+=mn;
		}
		return ret;
	}
};

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		bool fn3=(n<=210),fA=1,fB=1;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
			if(a[i][3]!=0) fA=fB=0;
			if(a[i][2]!=0) fA=0;
		}
		if(fn3) cout<<BF::n3all()<<'\n';
		else if(fA) cout<<BF::spc_A()<<'\n';
		else if(fB) cout<<BF::spc_B()<<'\n';
		else cout<<BF::greedy()<<'\n';
	}
	return 0;
}
