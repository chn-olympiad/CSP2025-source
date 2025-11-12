#include<bits/stdc++.h>
using namespace std;
const long long MAXN=256004,MAXP=5001006,HASH=998244853,Hash=233;
long long n,q,M,M1,M2,nxt[MAXN],ah[MAXN],bh[MAXN],mh[MAXN],lh[MAXP],hm,rh[MAXP],poww[MAXP],lenl[MAXN],lenm[MAXN],lenr[MAXN],ll,lr;
char s1[MAXP],s2[MAXP],s[MAXP],slis[MAXP],tlis[MAXP];
map<long long,long long> top;
long long gethash()
{
	long long i,t=0;
	for(i=1;i<=M;i++)
	{
		t=(t*Hash)%HASH;
		t=(t+s[i])%HASH;
	}
	return t;
}
long long ehash(long long l,long long r)
{
	return ((lh[r]-lh[l-1]*poww[r-l+1]%HASH)+HASH)%HASH;
}
long long fhash(long long l,long long r)
{
	return ((rh[r]-rh[l-1]*poww[r-l+1]%HASH)+HASH)%HASH;
}
void inss(char c)
{
	M++;
	s[M]=c;
	return;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long i,j,m,t,ans=0;
	long long L,R;
	scanf("%lld %lld",&n,&q);
	poww[0]=1;
	for(i=1;i<=MAXP-1;i++)
	{
		poww[i]=(poww[i-1]*Hash)%HASH;
	}
	for(i=1;i<=n;i++)
	{
		scanf("\n%s %s",s1+1,s2+1);
		m=strlen(s1+1);
		L=m+1;
		R=0;
		M=0;
		for(j=1;j<=m;j++)
		{
			if(s1[j]!=s2[j])
			{
				L=min(L,j);
				R=max(R,j);
			}
		}
		if(R<L)
		{
//			for(j=1;j<=m;j++)
//			{
//				inss(s1[j]);
//			}
			continue;
		}
		else
		{
			lenl[i]=L-1;
			lenm[i]=R-L+1;
			lenr[i]=m-R;
			for(j=1;j<=L-1;j++)
			{
				inss(s1[j]);
			}
			ah[i]=gethash();
			M=0;
			for(j=L;j<=R;j++)
			{
				inss(s1[j]);
				inss(s2[j]);
			}
			mh[i]=gethash();
			nxt[i]=top[mh[i]];
			top[mh[i]]=i;
			M=0;
			for(j=R+1;j<=m;j++)
			{
				inss(s1[j]);
			}
			bh[i]=gethash();
			M=0;
		}
	}
	for(i=1;i<=q;i++)
	{
		scanf("\n%s %s",s1+1,s2+1);
		m=strlen(s1+1);
		t=strlen(s2+1);
		if(m!=t)
		{
			printf("0\n");
			continue;
		}
		L=m+1;
		R=0;
		for(j=1;j<=m;j++)
		{
			if(s1[j]!=s2[j])
			{
				L=min(L,j);
				R=max(R,j);
			}
		}
		if(R<L)
		{
//			for(j=1;j<=m;j++)
//			{
//				inss(s1[j]);
//			}
			printf("0\n");
			continue;
		}
		else
		{
			ll=L-1;
			lr=m-R;
			M=0;
			for(j=1;j<=L-1;j++)
			{
				inss(s1[j]);
			}
			lh[0]=0;
			for(j=1;j<=M;j++)
			{
				lh[j]=(lh[j-1]*Hash+s[j])%HASH;
			}
			M=0;
			for(j=L;j<=R;j++)
			{
				inss(s1[j]);
				inss(s2[j]);
			}
			hm=gethash();
			M=0;
			for(j=R+1;j<=m;j++)
			{
				inss(s1[j]);
			}
			rh[0]=0;
			for(j=1;j<=M;j++)
			{
				rh[j]=(rh[j-1]*Hash+s[j])%HASH;
			}
			M=0;
			t=top[hm];
			ans=0;
			while(t>0)
			{
				if(lenl[t]<=ll&&lenr[t]<=lr)
				{
					if(ehash(ll-lenl[t]+1,ll)==ah[t]&&fhash(1,lenr[t])==bh[t])
					{
						ans++;
					}
				}
				t=nxt[t];
			}
			printf("%lld\n",ans);
		}
	}
	for(i=1;i<=M2;i++)
	{
		M++;
		s[M]=tlis[i];
	}
	for(i=1;i<=M1;i++)
	{
		M++;
		s[M]=slis[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
