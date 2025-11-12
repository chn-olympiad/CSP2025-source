#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,cl[4],ans,cln[4],t;
bool check[MAXN];
struct S
{
	int cv[4],ch[4],num;
}s[MAXN];
bool cmp(S x,S y)
{
	return x.cv[x.ch[1]]-x.cv[x.ch[2]]>y.cv[y.ch[1]]-y.cv[x.ch[2]];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("r","club.in",stdin);
	freopen("w","club.out",stdout);
	cin>>t;
	while(t--)
	{
		memset(s,0,sizeof(s));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].cv[1]>>s[i].cv[2]>>s[i].cv[3];
			if(s[i].cv[1]>=s[i].cv[2]&&s[i].cv[1]>=s[i].cv[3])
			{
				s[i].num++;
				s[i].ch[s[i].num]=1;
			}
			if(s[i].cv[2]>=s[i].cv[1]&&s[i].cv[2]>=s[i].cv[3])
			{
				s[i].num++;
				s[i].ch[s[i].num]=2;
			}
			if(s[i].cv[3]>=s[i].cv[2]&&s[i].cv[3]>=s[i].cv[1])
			{
				s[i].num++;
				s[i].ch[s[i].num]=3;
			}
			if(s[i].num==1)
			{
				if(s[i].cv[1]>=s[i].cv[2]&&s[i].cv[1]<=s[i].cv[3])
				{
					s[i].ch[2]=1;
				}
				if(s[i].cv[2]>=s[i].cv[1]&&s[i].cv[2]<=s[i].cv[3])
				{
					s[i].ch[2]=2;
				}
				if(s[i].cv[3]>=s[i].cv[2]&&s[i].cv[3]<=s[i].cv[1])
				{
					s[i].ch[2]=3;
				}
				if(s[i].cv[1]>=s[i].cv[3]&&s[i].cv[1]<=s[i].cv[2])
				{
					s[i].ch[2]=1;
				}
				if(s[i].cv[2]>=s[i].cv[3]&&s[i].cv[2]<=s[i].cv[1])
				{
					s[i].ch[2]=2;
				}
				if(s[i].cv[3]>=s[i].cv[1]&&s[i].cv[3]<=s[i].cv[2])
				{
					s[i].ch[2]=3;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cl[s[i].ch[1]]++;
			if(s[i].num!=1)cln[s[i].ch[1]]++;
		}
		if(cl[1]-cln[1]<=n/2&&cl[2]-cln[2]<=n/2&&cl[3]-cln[3]<=n/2)
		{
			for(int i=1;i<=n;i++)
			{
				ans+=s[i].cv[s[i].ch[1]];
				//cout<<s[i].cv[1]<<" "<<s[i].cv[2]<<" "<<s[i].cv[3]<<" "<<s[i].ch[1]<<" "<<s[i].ch[2]<<" "<<s[i].ch[3]<<" "<<s[i].num<<endl;
			}
			cout<<ans<<endl;
		}
		else
		{
			int clmx,count=0;
			if(cl[1]>cl[2]&&cl[1]>cl[3])
			{
				clmx=1;
			}
			if(cl[2]>cl[1]&&cl[2]>cl[3])
			{
				clmx=2;
			}
			if(cl[3]>cl[2]&&cl[3]>cl[1])
			{
				clmx=3;
			}
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(s[i].ch[1]==clmx&&count<n/2)
				{
					//cout<<s[i].cv[1]<<" "<<s[i].cv[2]<<" "<<s[i].cv[3]<<" "<<s[i].ch[1]<<" "<<s[i].ch[2]<<" "<<s[i].ch[3]<<" "<<s[i].num<<endl;
					ans+=s[i].cv[s[i].ch[1]];
					count++;
				}
				else if(s[i].ch[1]==clmx)
				{
					//cout<<s[i].cv[1]<<" "<<s[i].cv[2]<<" "<<s[i].cv[3]<<" "<<s[i].ch[1]<<" "<<s[i].ch[2]<<" "<<s[i].ch[3]<<" "<<s[i].num<<endl;
					ans+=s[i].cv[s[i].ch[2]];
				}
				else 
				{
					//cout<<s[i].cv[1]<<" "<<s[i].cv[2]<<" "<<s[i].cv[3]<<" "<<s[i].ch[1]<<" "<<s[i].ch[2]<<" "<<s[i].ch[3]<<" "<<s[i].num<<endl;
					ans+=s[i].cv[s[i].ch[1]];
				}
			}
			cout<<ans;
		}
	}
	cout<<endl;
	return 0;
}
