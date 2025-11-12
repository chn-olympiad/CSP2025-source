#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10,K=5e6+10;
int n,q,pr[N],ls[N];
unsigned long long base=37,pw[K];
vector <unsigned long long > hs[N][2];
vector <int > v[K]; 
string s[N][2],t[N][2];

unsigned long long ask(int k,int l,int r)
{
	if(l>r) return 0;
	unsigned long long ms=0;
	if(l!=0) ms=hs[k][0][l-1];
	return hs[k][0][r]-ms*pw[r-l+1];
}

unsigned long long ask2(int k,int l,int r)
{
	if(l>r) return 0;
	unsigned long long ms=0;
	if(l!=0) ms=hs[k][1][l-1];
	return hs[k][1][r]-ms*pw[r-l+1];
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=K-10;i++) pw[i]=pw[i-1]*base;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		int len=s[i][0].size(),fr=-1,ed=-1;
		for(int j=0;j<len;j++) 
		{
			if(s[i][0][j]!=s[i][1][j]) 
			{
				if(fr==-1) fr=j;
				ed=j;
			} 
		}
		hs[i][0].resize(len+3),hs[i][1].resize(len+3);
		pr[i]=fr,ls[i]=ed;
		hs[i][0][0]=s[i][0][0]-'a'+1,hs[i][1][0]=s[i][1][0]-'a'+1;
		for(int j=1;j<len;j++) 
		{
			hs[i][0][j]=hs[i][0][j-1]*base+s[i][0][j]-'a'+1;
			hs[i][1][j]=hs[i][1][j-1]*base+s[i][1][j]-'a'+1;
		}
		if(fr!=-1) v[ed-fr+1].push_back(i);
	}
	hs[n+1][0].resize(K),hs[n+1][1].resize(K);
	for(int i=1;i<=q;i++)
	{
		cin>>t[i][0]>>t[i][1];
		int len=t[i][0].size(),fr=-1,ed=-1;
		if((int)t[i][1].size()!=len) 
		{
			printf("0\n");
			continue ;
		} 
		for(int j=0;j<len;j++) 
		{
			if(t[i][0][j]!=t[i][1][j]) 
			{
				if(fr==-1) fr=j;
				ed=j;
			} 
		}
		hs[n+1][0][0]=t[i][0][0]-'a'+1,hs[n+1][1][0]=t[i][1][0]-'a'+1;
		for(int j=1;j<len;j++) 
		{
			hs[n+1][0][j]=hs[n+1][0][j-1]*base+t[i][0][j]-'a'+1;
			hs[n+1][1][j]=hs[n+1][1][j-1]*base+t[i][1][j]-'a'+1;
		}
		int res=0;
		for(int k:v[ed-fr+1]) 
		{
			if(pr[k]<=fr&&len-ed>=(int)s[k][0].size()-ls[k]) 
			{
				int p=s[k][0].size()-ls[k]-1;
				if(ask(k,0,pr[k]-1)==ask(n+1,fr-pr[k],fr-1)&&ask(k,ls[k]+1,ls[k]+p)==ask(n+1,ed+1,ed+p))
				{
					if(ask(k,pr[k],ls[k])==ask(n+1,fr,ed)&&ask2(k,pr[k],ls[k])==ask2(n+1,fr,ed)) res++;
				} 
			}
		}
		printf("%d\n",res);
	}
	return 0;	
}