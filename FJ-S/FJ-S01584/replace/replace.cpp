#include<bits/stdc++.h>
using namespace std;
int rd()
{
	int asn=0;char ch=getchar();
	while('0'>ch||'9'<ch)ch=getchar();
	while('0'<=ch&&ch<='9')
	{
		asn=(asn<<3)+(asn<<1)+(ch-'0');
		ch=getchar();
	}
	return asn;
}
int n,q,cnt,l[1001];
char s[1001][2001][2],t1[1001],t2[1001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=rd(),q=rd();
	for(int i=1;i<=n;i++)
	{
		char ch=getchar();
		while('a'>ch||'z'<ch)ch=getchar();
		cnt=0;
		while('a'<=ch&&ch<='z')
		{
			ch=getchar();
			s[i][++cnt][0]=ch;
		}
		while('a'>ch||'z'<ch)ch=getchar();
		cnt=0;
		while('a'<=ch&&ch<='z')
		{
			ch=getchar();
			s[i][++cnt][1]=ch;
		}
		l[i]=cnt;
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		char ch=getchar();
		while('a'>ch||'z'<ch)ch=getchar();
		cnt=0;
		while('a'<=ch&&ch<='z')
		{
			ch=getchar();
			t1[++cnt]=ch;
		}
		while('a'>ch||'z'<ch)ch=getchar();
		cnt=0;
		while('a'<=ch&&ch<='z')
		{
			ch=getchar();
			t2[++cnt]=ch;
		}
		int ln=cnt;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=ln-l[j]+1;k++)
			{
				int b=1;
				for(int k1=1;k1<=l[j];k1++)
					if(s[j][k1][0]!=t1[k+k1-1]||s[j][k1][1]!=t2[k+k1-1])
					{
						b=0;
						break;
					}
				ans+=b;
			}
		}		
		printf("%d\n",ans);
	}
	return 0;
}
