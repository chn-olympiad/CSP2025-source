//GZ-S00124 贵阳市白云区华师一学校 姜裕伟
#include<bits/stdc++.h>
using namespace std;
string s,anss;
struct aa
{
	string a,b;
}a[200005];
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b;
	}
	while(q--)
	{
		int ans=0;
		cin>>s>>anss;
		string ss;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<s.size();j++)
			{
				bool bb=1;
				for(int k=0;k<a[i].a.size();k++)
				{
					if(s[j+k]!=a[i].a[k]) bb=0;
				}
				if(bb)
				{
					ss.clear();
					for(int k=0;k<s.size();k++)
					{
						if(k==j)
						{
							for(int r=0;r<a[i].a.size();r++)
							{
								ss.push_back(a[i].b[r]);
							}
							k+=a[i].a.size()-1;
						}
						else 
						{
							ss.push_back(s[k]);
						}
					}
					if(ss==anss) ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

