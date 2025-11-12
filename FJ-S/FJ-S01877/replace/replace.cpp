#include<bits/stdc++.h>
using namespace std;
int n,q,f,ff;
bool fl;
long long cnt;
struct node{
	string a,b;
}s[10010];
string x,y;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i].a>>s[i].b;
	while(q--)
	{
		cin>>x>>y;
		cnt=0;
		for(int i=0;i<x.size();i++)
		{
			if(x[i]!=y[i])
			{
				f=i;
				break;
			}
		}
		for(int i=x.size()-1;i>=0;i--)
		{
			if(x[i]!=y[i])
			{
				ff=i;
				break;
			}
		}		
		for(int i=1;i<=n;i++)
		{
			int l=ff-s[i].a.size()+1;
			for(int j=max(0,l);j<=f;j++)
			{
				fl=0;
				for(int k=0;k<s[i].a.size();k++)
				{
					if((x[j+k]!=s[i].a[k])||(s[i].b[k]!=y[j+k]))
					{
						fl=1;
						break;	
					}	
				}
				if(fl==0)
					cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
