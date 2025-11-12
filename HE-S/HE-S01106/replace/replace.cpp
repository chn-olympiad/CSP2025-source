#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string c[N][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		cin>>c[i][1]>>c[i][2];
	while(q--)
	{
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size())
		{
			printf("0\n");
			continue;
		}
		s=" "+s;
		t=" "+t;
		int id=0,ans=0;
		for(int i=1;i<s.size();i++)
			if(s[i]!=t[i])
			{
				id=i;
				break;
			}
		for(int i=1;i<=id;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(s.size()-id-c[j][1].size()+1<0)
					continue;
				bool flag=true;
				for(int k=0;k<c[j][1].size();k++)
					if(s[i+k]!=c[j][1][k] || t[i+k]!=c[j][2][k])
					{
						flag=false;
						break;
					}
				if(flag)
				{
					for(int k=id+c[j][1].size();k<s.size();k++)
						if(s[k]!=t[k])
						{
							flag=false;
							break;
						}
					ans+=flag;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
