#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string s[10001],ss[10001];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>ss[i];
	}
	for(int i=1;i<=m;i++)
	{
		string a,b;
		int ans=0;
		cin>>a>>b;
		for(int j=1;j<=i;j++)
		{
			int idx=a.find(s[j]);
			string p=a,q="";
			while(idx!=-1)
			{
				if(idx==-1)break;
				p[idx]='1';
				for(int k=0;k<a.size();k++)
				{
					if(k>=idx&&k<=idx+s[j].size()-1)q[k]=ss[j][k-idx];
					else q[k]=a[k];
				}
				if(q==b)ans++;
				idx=p.find(s[j]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
