#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	vector<vector<string>> s(n,vector<string>(2));
	for(int i=0;i<n;i++) cin>>s[i][0]>>s[i][1];
	while(q--)
	{
		string a,b;cin>>a>>b;
		if(a.size()!=b.size())
		{
			cout<<"0\n";
			continue;
		}
		int ans=0;int l=-1,r=-1;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]!=b[i])
			{
				l=i;
				break;
			}
		}
		for(int i=a.size()-1;i>=0;i--)
		{
			if(a[i]!=b[i])
			{
				r=i;
				break;
			}
		}
		for(int k=0;k<n;k++)
		{
			int len=s[k][0].size();
			for(int i=max(r-len+1,0);i+len-1<a.size()&&i<=l;i++)
			{
				
				bool f=true;
				//cout<<k<<" "<<i<<"\n";
				for(int j=i;j<i+len;j++)
				{
					//cout<<a[j]<<s[k][0][j]<<" "<<b[j]<<s[k][1][j]<<"\n";
					if(a[j]!=s[k][0][j-i]||b[j]!=s[k][1][j-i])
					{
						f=false;
						break;
					}
				}
				if(f)
				{
					ans++;
					//cout<<k<<" "<<i<<"\n";
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
