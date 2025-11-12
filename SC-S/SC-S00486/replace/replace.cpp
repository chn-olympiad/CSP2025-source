#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=500010;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,q;
string s1[N],s2[N];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		int sum=0;
		string s,t,d1,d2;
		d1.clear();d2.clear();
		cin>>s>>t;
		int len=s.size(),beg,end;
		for(int i=0;i<len;i++)
		{
			if(s[i]!=t[i])
			{
				beg=i;
				break;
			}
		}
		for(int i=len-1;i>=0;i--)
		{
			if(s[i]!=t[i])
			{
				end=i;
				break;
			}
		}
		for(int i=beg;i<=end;i++) d1=d1+s[i],d2=d2+t[i];
		len=d1.size();
		for(int i=1;i<=n;i++)
		{
			if(s1[i].size()<len) continue;
			for(int j=0;j<s1[i].size();j++)
			{
				if(s1[i][j]==d1[0]&&s2[i][j]==d2[0])
				{
					int flag=0;
					for(int k=0;k<len;k++)
					{
						if(s1[i][j+k]!=d1[k]||s2[i][j+k]!=d2[k])
						{
							flag=1;
							break;
						}
					}
					if(!flag)
					{
						sum++;
						break;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
//Bocchi the Rock!
