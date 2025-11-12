#include<bits/stdc++.h>
using namespace std;

int n,q,cnt;
string s[200005],a,b;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	while(q--)
	{
		cnt=0;
		cin>>a>>b;
		string m=a;
		for(int i=1;i<=n;i++)
		{
			if(m.find(s[i])!=-1)
			{
				int a=s[i].size();
				m.replace(m.find(s[i]),a,s[i]);
				if(m==b) cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
