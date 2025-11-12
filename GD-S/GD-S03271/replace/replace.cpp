#include <bits/stdc++.h>
using namespace std;

const int N = 5000010;
const unsigned long long p = 131;
unsigned long long pw[N];
int n,q;
int len[N];
unsigned long long hs1[N],hs2[N];
unsigned long long h[2][N];
unsigned long long gt(int l,int r,int f)
{
	return h[f][r]-h[f][l-1]*pw[r-l+1];
}
char s1[N],s2[N];
int qz[N],hz[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	pw[0]=1;
	for(int i=1;i<=5000000;i++) pw[i]=pw[i-1]*p;
	for(int i=1;i<=n;i++)
	{
		scanf("%s%s",s1+1,s2+1);
		int t=strlen(s1+1);len[i]=t;
		for(int j=1;j<=t;j++) hs1[i]=hs1[i]*p+s1[j],hs2[i]=hs2[i]*p+s2[j];
	}
	while(q--)
	{
		scanf("%s%s",s1+1,s2+1);
		int t=strlen(s1+1);
		for(int i=1;i<=t;i++)
		{
			h[0][i]=h[0][i-1]*p+s1[i];
			h[1][i]=h[1][i-1]*p+s2[i];
			qz[i]+=qz[i-1];
			if(s1[i]==s2[i]) qz[i]++;
		}
		for(int i=t;i>=1;i--)
		{
			hz[i]+=hz[i+1];
			if(s1[i]==s2[i]) hz[i]++;
		}
		int cnt=0;
		for(int i=1;i<=t;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(len[j]>i) continue;
			//	cout<<gt(i-len[j]+1,i,0)<<" "<<gt(i-len[j]+1,i,1)<<" "<<hs1[j]<<" "<<hs2[j]<<endl;
				if(qz[i-len[j]]==i-len[j] && hz[i+1]==t-i && gt(i-len[j]+1,i,0)==hs1[j] && gt(i-len[j]+1,i,1)==hs2[j]) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
