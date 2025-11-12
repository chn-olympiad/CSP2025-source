#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	string str1,str2;
	int l,f,s;
}q[1000005];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>q[i].str1>>q[i].str2;
		q[i].l=q[i].str1.size();
	}
	int opt=0,s=0;
	for(int i=1;i<=q[1].l;i++)
	{
		if(q[1].str1[i-1]=='b')
			s++;
		else if(q[1].str1[i-1]=='a')
			opt=opt;
		else opt=1;
	}
	if(opt==0&&s==1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=q[i].l;j++)
			{
				if(q[i].str1[j-1]=='b')
					q[i].f=j;
				if(q[i].str2[j-1]=='b')
					q[i].s=j;
			}
		}
		while(m--)
		{
			string str1,str2;
			cin>>str1>>str2;
			if(str1.size()!=str2.size())
			{
				cout<<0<<endl;
				continue;
			}
			int f,s;
			for(int j=1;j<=str1.size();j++)
			{
				if(str1[j-1]=='b')
					f=j;
				if(str2[j-1]=='b')
					s=j;
			}
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(f-s==q[i].f-q[i].s&&f>=q[i].f&&str1.size()-s>=q[i].l-q[i].s)
					ans++;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	while(m--)
	{
		string str1,str2;
		cin>>str1>>str2;
		if(str1.size()!=str2.size())
		{
			cout<<0<<endl;
			continue;
		}
		int l=1e9,r=0;
		for(int i=1;i<=str1.size();i++)
		{
			if(str1[i-1]!=str2[i-1])
			{
				l=min(l,i);
				r=max(r,i);
			}
		}
		int ans=0;
		for(int i=1;i<=l;i++)
		{
			for(int j=r;j<=str1.size();j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(q[k].l==j-i+1)
					{
						int flag=0;
						for(int u=0;u<q[k].l;u++)
						{
							if(q[k].str1[u]==str1[i+u-1]&&q[k].str2[u]==str2[i+u-1])
								flag=flag;
							else flag=1;
						}
						if(flag==0)
							ans++;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
