#include<cstdio>
#include<cstring>
#include<utility>
#include<map>
using namespace std;

#define LEN 5000005

namespace code
{
	int n,q;
	const int mod1=1e9+7,base1=13331,mod2=998244353,base2=19937;
	int pw1[LEN],pw2[LEN];
	map<pair<pair<pair<int,int>,int>,pair<int,int> >,int> fromto;
	int shash1[LEN],shash2[LEN];
	int fhash1[LEN],fhash2[LEN];
	int ghash1[LEN],ghash2[LEN];
	
	int ny(int a,int mod)
	{
		int b=mod-2,res=1;
		while(b)
		{
			if(b&1)
				res=(long long)res*a%mod;
			a=(long long)a*a%mod;
			b>>=1;
		}
		return res;
	}
	
	void init(char s[],int lens,int hash1[],int hash2[])
	{
		pw1[0]=1;
		pw2[0]=1;
		for(int i=1;i<=lens;++i)
			pw1[i]=(long long)pw1[i-1]*base1%mod1,
			pw2[i]=(long long)pw2[i-1]*base2%mod2;
		for(int i=1;i<=lens;++i)
			hash1[i]=(hash1[i-1]+(long long)pw1[i]*(s[i]-'a'+1)%mod1)%mod1,
			hash2[i]=(hash2[i-1]+(long long)pw2[i]*(s[i]-'a'+1)%mod2)%mod2;
	}
	
	int geths(int l,int r,int hash[],int pw[],int mod)
	{
		if(l>r)
			return 0;
		return ((long long)hash[r]+mod-hash[l-1])%mod*ny(pw[l-1],mod)%mod;
	}
	
	signed main()
	{
		scanf("%d%d",&n,&q);
		char s1[LEN],s2[LEN];
		while(n--)
		{
			scanf("%s%s",s1+1,s2+1);
			int lens1=strlen(s1+1),lens2=strlen(s2+1);
			init(s1,lens1,shash1,shash2);
			int t1=shash1[lens1],t2=shash2[lens1];
			init(s2,lens2,shash1,shash2);
			++fromto[make_pair(make_pair(make_pair(t1,t2),lens1),make_pair(shash1[lens2],shash2[lens2]))];
		}
		while(q--)
		{
			scanf("%s%s",s1+1,s2+1);
			int lens1=strlen(s1+1),lens2=strlen(s2+1);
			init(s1,lens1,fhash1,fhash2);
			init(s2,lens2,ghash1,ghash2);
			int ans=0;
			for(int l=1;l<=lens1;++l)
				for(int r=l;r<=lens1;++r)
					if
					(
						geths(1,l-1,fhash1,pw1,mod1)==geths(1,l-1,ghash1,pw1,mod1)&&
						geths(1,l-1,fhash2,pw2,mod2)==geths(1,l-1,ghash2,pw2,mod2)&&
						geths(r+1,lens1,fhash1,pw1,mod1)==geths(r+1,lens2,ghash1,pw1,mod1)&&
						geths(r+1,lens1,fhash2,pw2,mod2)==geths(r+1,lens2,ghash2,pw2,mod2)
					)
						ans+=fromto[make_pair(make_pair(make_pair(geths(l,r,fhash1,pw1,mod1),geths(l,r,fhash2,pw2,mod2)),r-l+1),make_pair(geths(l,r,ghash1,pw1,mod1),geths(l,r,ghash2,pw2,mod2)))];
			printf("%d\n",ans);
		}
		return 0;
	}
}

signed main()
{
	// freopen("replace3.in","r",stdin);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	code::main();
	return 0;
}