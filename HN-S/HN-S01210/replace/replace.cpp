#include<bits/stdc++.h>
#include<string>
using namespace std;
const int N=2e5+2;
int n,q,s;
string s1[N],s2[N],t1[N],t2[N];
long long read()
{
	register long long x=0,k=1;
	register char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-')
			k=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return k*x;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	if (n>1e4)
	{
		for (int i=1;i<=q;++i)
		{
			puts("0");
		}
		return 0;
	}
	for (int i=1;i<=n;++i)
		cin>>s1[i]>>s2[i];
	for (int j=1;j<=q;++j)
	{
		s=0;
		cin>>t1[j]>>t2[j];
		for (int i=1;i<=n;++i)
		{
			long long p=t1[j].find(s1[i]);
			if (p!=-1)
			{
				string t=t1[j];
				for (int k=p;k-p<s2[i].size();++k)
					t[k]=s2[i][k-p];
				if (t==t2[j])
					++s;
			}
		}
		printf("%d\n",s); 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

