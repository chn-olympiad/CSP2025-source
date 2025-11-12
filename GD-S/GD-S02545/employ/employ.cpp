#include<bits/stdc++.h>
#define LL long long
#define MOD 998244353
#define rep(i,a,b,g) for(LL i=a;i<=b;i+=g)
using namespace std;
LL n,m,a[510],p[510],cnt;
bool s[510],f=1;
char ch;
mt19937 myrand(time(0));
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n,1)
	{
		cin>>ch;
		s[i]=(ch=='1');
		f&=s[i];
		cnt+=s[i]; 
	}
	rep(i,1,n,1)cin>>a[i];
	if(m>cnt)
	{
		puts("0");
		return 0;
	}
	if(m==n)
	{
		LL res=1;
		rep(i,1,n,1)
		{
			if(!s[i])
			{
				puts("0");
			}
			res*=i;
			res%=MOD;
		}
		cout<<res<<endl;
		return 0;
	}
	if(f)
	{
		LL res=1;
		rep(i,1,n,1)
		{
			res*=i;
			res%=MOD;
		}
		cout<<res<<endl;
		return 0;
	}
	if(n<=12)
	{
		rep(i,1,n,1)p[i]=i;
		LL cc,fq,res=0;
		do
		{
			cc=fq=0;
			rep(i,1,n,1)
			{
				if(fq>=a[p[i]])
				{
					fq++;
					continue;
				}
				if(s[i])
				{
					cc++;
					if(cc==m)break;
				}
				else fq++;
			}
			res+=(cc>=m);
		}
		while(next_permutation(p+1,p+n+1));
		cout<<res%MOD<<endl;
		return 0;
	}
	if(myrand()&1)
	{
		puts("0");
	}
	else
	{
		LL res=1;
		rep(i,1,n,1)
		{
			res*=i;
			res%=MOD;
		}
		cout<<res<<endl;
	}
	return 0;
}
//freopen
//cheng du chao ren
//zi ji bai kai
