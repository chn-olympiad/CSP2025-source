#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,ans;
string s[N][2];
int finds(string s,string t,int x)
{
	for(int i=x;i<int(s.size());i++)
	{
		int j=i,k=0;
		while(s[j]==t[k]&&j<s.size())j++,k++;
		if(k==t.size())return j-k;
	}
	return -1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	while(q--)
	{
		ans=0;
		string p,t;
		cin>>p>>t;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<p.size();j++)
			{
				int now=finds(p,s[i][0],j);
				if(now>=0)
				{
					string pp=p;
					for(int l=now,k=0;k<int(s[i][0].size());l++,k++)
						pp[l]=s[i][1][k];
					if(pp==t)
						ans++;
				}
				
			}
		}
		cout<<ans/2<<endl;
	}
	return 0;
}
