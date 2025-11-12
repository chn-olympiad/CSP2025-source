#include<bits/stdc++.h>
#define B 37
#define mod 998244353
#define mod1 1000000007
#define mod2 1000000003
using namespace std;
long long n,q,qp[5000005],qp1[5000005],qp2[5000005];
char s[5000005],t[5000005];
map<long long,map<long long,long long> >mp;
map<int,map<int,int> >mp1;
map<int,bool>mp2;
map<int,bool>mp3;

void read(long long &x)
{
	x=0;
	char ch=0;
	while('0'>ch||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
}
long long qpow(long long a,long long b,long long p)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n);read(q);
	long long c=qpow(B,mod-2,mod),cc=qpow(B,mod1-2,mod1),ccc=qpow(B,mod2-2,mod2);
	qp[0]=1;
	for(int i=1;i<=5e6;i++) qp[i]=qp[i-1]*c%mod;
	qp1[0]=1;
	for(int i=1;i<=5e6;i++) qp1[i]=qp1[i-1]*cc%mod1;
	qp2[0]=1;
	for(int i=1;i<=5e6;i++) qp2[i]=qp2[i-1]*ccc%mod2;
	
	
	for(int j=1;j<=n;j++)
	{
		scanf("%s%s",s+1,t+1);
		long long x=1;
		for(int i=1;s[i];i++)x=i;
		if(x<=400)
		{
			
			long long w=0;
			for(int i=1;s[i];i++)w=(w*B%mod+s[i]-'a'+1)%mod;
			long long ww=0;
			for(int i=1;t[i];i++)ww=(ww*B%mod+t[i]-'a'+1)%mod;
			mp1[w][ww]++;mp2[w]=1;
		}
		else
		{
			long long w=0;
			for(int i=1;s[i];i++)w=(w*B%mod+s[i]-'a'+1)%mod;
			long long w1=0;
			for(int i=1;s[i];i++)w1=(w1*B%mod1+s[i]-'a'+1)%mod1;
			long long w2=0;
			for(int i=1;s[i];i++)w2=(w2*B%mod2+s[i]-'a'+1)%mod2;
			
			long long ww=0;
			for(int i=1;t[i];i++)ww=(ww*B%mod+t[i]-'a'+1)%mod;
			long long ww1=0;
			for(int i=1;t[i];i++)ww1=(ww1*B%mod1+t[i]-'a'+1)%mod1;
			long long ww2=0;
			for(int i=1;t[i];i++)ww2=(ww2*B%mod2+t[i]-'a'+1)%mod2;
			mp3[((ww+mod-w)%mod)]=1;
			mp[((ww+mod-w)%mod)][((ww1+mod1-w1)%mod1)*((ww2+mod2-w2)%mod2)]++;
		}
		for(int i=1;s[i];i++)s[i]=0;
		for(int i=1;t[i];i++)t[i]=0;
	}
	
	while(q--)
	{
		long long ans=0,num=0;;
		scanf("%s%s",s+1,t+1);
		long long w=0;
		for(int i=1;s[i];i++)w=(w*B%mod+s[i]-'a'+1)%mod,num+=s[i]!=t[i];
		long long w1=0;
		for(int i=1;s[i];i++)w1=(w1*B%mod1+s[i]-'a'+1)%mod1;
		long long w2=0;
		for(int i=1;s[i];i++)w2=(w2*B%mod2+s[i]-'a'+1)%mod2;
		
		long long ww=0;
		for(int i=1;t[i];i++)ww=(ww*B%mod+t[i]-'a'+1)%mod;
		long long ww1=0;
		for(int i=1;t[i];i++)ww1=(ww1*B%mod1+t[i]-'a'+1)%mod1;
		long long ww2=0;
		for(int i=1;t[i];i++)ww2=(ww2*B%mod2+t[i]-'a'+1)%mod2;
		
		for(int i=1;s[i];i++)
		{
			long long ws=0,wws=0,p=0;
			for(int j=i;j<=i+399&&s[j];j++)
			{
				
				ws=(ws*B%mod+s[j]-'a'+1)%mod;
				
				wws=(wws*B%mod+t[j]-'a'+1)%mod;
				p+=s[j]!=t[j];
				if(p==num&&mp2.count(ws)&&mp1[ws].count(wws))ans+=mp1[ws][wws];
			}
			long long l=(ww+mod-w)%mod,ll=(ww2+mod2-w2)%mod2,r=(ww1+mod1-w1)%mod1;
			l=l*qp[i-1]%mod;ll=ll*qp2[i-1]%mod2;r=r*qp1[i-1]%mod1;
			if(mp3.count(l)&&mp[l].count(r*ll)) ans+=mp[l][r*ll];
		}
		
		for(int i=1;s[i];i++)s[i]=0;
		for(int i=1;t[i];i++)t[i]=0;
		printf("%lld\n",ans);
	}
	return 0;
}/*fc D:\GD-S00022\replace\replace.out D:\replace\replace3.ans*/
