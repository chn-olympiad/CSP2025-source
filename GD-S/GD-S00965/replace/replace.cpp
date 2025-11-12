#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double

int read()
{
	int x=0,f=1;
	char ch=' ';
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while ('0'<=ch&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

void prt(ll x)
{
	if (x==0)
	{
		putchar('0');
		return;
	}
	if (x<0) putchar('-'),x=-x;
	int stac[20],top=0;
	while (x)
	{
		stac[++top]=x%10;
		x/=10; 
	}
	while (top)
	{
		putchar(stac[top--]^48);
	}
	return;
}

const int maxn=1e4+10;
const ll p=131,mod=1e9+7;

int n,q;
string s1,s2,t1,t2;
int m[maxn],pp[maxn],h1[maxn][maxn],h2[maxn][maxn];
int H1[maxn],H2[maxn];
ll ans;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	n=read();q=read();
	for (int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		m[i]=s1.length();
		s1=" "+s1;s2=" "+s2;
		for (int j=1;j<=m[i];j++)
		{
			h1[i][j]=h1[i][j-1]*p%mod+(s1[j]-'a'+1);
			h2[i][j]=h2[i][j-1]*p%mod+(s2[j]-'a'+1);
			pp[j]=pp[j-1]*p%mod;
		}
	}
	while (q--)
	{
		cin>>t1>>t2;
		int len1=t1.length(),len2=t2.length();
		if (len1!=len2)
		{
			prt(0);putchar('\n');
		}
		else
		{
			ll ans=0;
			t1=" "+t1,t2=" "+t2;
			for (int j=1;j<=len1;j++)
			{
				H1[j]=H1[j-1]*p%mod+(t1[j]-'a'+1);
				H2[j]=H2[j-1]*p%mod+(t2[j]-'a'+1);
			}
			for (int L=0;L<len1;L++)
			{
				for (int R=L+1;R<len1;R++)//1->L,L+1->R,R+1->n
				{
					ll Lh1=H1[L],Lh2=H2[L];
					ll mh1=H1[R]-(H1[L]*pp[R-L]%mod)+mod,mh2=H2[R]-(H2[L]*pp[R-L]%mod)+mod;
					ll Rh1=H1[len1]-(H1[R]*pp[len1-R]%mod)+mod,Rh2=H2[len1]-(H2[R]*pp[len1-R]%mod)+mod;
					Rh1%=mod;Rh2%=mod;mh1%=mod;mh2%=mod;
					if (Lh1!=Lh2||Rh1!=Rh2) continue;
					for (int i=1;i<=n;i++)
					{
						if (h1[i][m[i]]%mod==mh1&&h2[i][m[i]]%mod==mh2)
						{
							ans++;
						}
					}
				}
			}
			prt(ans);putchar('\n');
		}
	}
	
	
	return 0;
}
