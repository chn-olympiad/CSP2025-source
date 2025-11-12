#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=2e5+10;
int n,q;
char a[N][2000];
char b[N][2000];
char s[N],t[N];
int nxt[N];
char p[N];
int len_s;
void KMP()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int ans=0;
	for(int i=1;i<=len_s;i++)
	{
		p[i]=s[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k=0;
		int lena=strlen(a[i]+1);
		for(int j=2;j<=lena;j++)
		{
			while(k&&a[i][j]!=a[i][k+1])k=nxt[k];
			if(a[i][j]==a[i][k+1])k++;
			nxt[j]=k;
		}
		k=0;
		vector<int>cnt;
		for(int j=1;j<=len_s;j++)
		{
			while(k==lena||(k&&s[j]!=a[i][k+1]))k=nxt[k];
			if(s[j]==a[i][k+1])k++;
			if(k==lena)
			{
				cnt.push_back(j);
			}
		}
		for(int j=0;j<cnt.size();j++)
		{
//			cout<<cnt[j]<<" ";
			int begin=cnt[j]-lena+1;
			int o=1;
//			cout<<begin<<" ";
			for(int k=begin;o<=lena;o++,k++)
			{
				s[k]=b[i][o];
//				cout<<b[i][o]<<" ";
			}
//			cout<<endl;
//			for(int i=1;i<=len_s;i++)
//			{
//				cout<<s[i];
//			}
//			cout<<endl;
			bool flag=false;
			for(int k=1;k<=len_s;k++)
			{
				if(s[k]!=t[k])
				{
					flag=true;
					break;
				}
			}
			if(flag==false)
			{
				ans++;
			}
			for(int k=1;k<=len_s;k++)
			{
				s[k]=p[k];
			} 
		}
		for(int i=1;i<=lena;i++)
		{
			nxt[i]=0;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a[i]+1);
		scanf("%s",b[i]+1);
	}
	while(q--)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		len_s=strlen(s+1);
		KMP();
	}
	return 0;
}
/*
4 2
xabcx xadex
ad cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
