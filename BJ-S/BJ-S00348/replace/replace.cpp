#include <bits/stdc++.h>
using namespace std;
string a[200010][2];
int b[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0];
		cin>>a[i][1];
		for(int j=0;j<(int)a[i][0].length();j++)
		{
			if(a[i][0][j]!=a[i][1][j])b[i]++;
		}
	}
	while(q--)
	{
		long long ans=0;
		string s1,s2;
		cin>>s1>>s2;
		long long l=s1.length();
		if(s1.length()!=s2.length())
		{
			cout<<0<<endl;
			continue;
		}
		int cnt=0;
		for(int i=0;i<l;i++)
		{
			if(s1[i]!=s2[i])cnt++;
		}
		for(int i=0;i<l;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int f=1,ll=a[j][0].length();
				if(i+ll>l||b[j]!=cnt)continue;
				for(int k=0;k<ll;k++)
				{
					if(s1[i+k]!=a[j][0][k]||s2[i+k]!=a[j][1][k])
					{
						f=0;
						break;
					}
				}
				if(f==1)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
