#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<string> a[2];
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m; cin >>n >>m;
	for(int i=1;i<=n;i++) 
	{
		string s,ss; cin >>s >>ss;
		if(s.size()!=ss.size()) continue;
		a[0].push_back(s);
		a[1].push_back(ss);
	}
	while(m--)
	{
		long long ans=0;
		string s,ss;
		cin >>s >>ss;
		for(int i=0;i<a[0].size();i++)
		{
			int p1=s.size(),p2=a[0][i].size();
			for(int j=0;j<=p1-p2;j++)
			{
				int flg=1;
				for(int k=0;k<a[0][i].size();k++) if(s[j+k]!=a[0][i][k])
				{
					flg=0;
					break;
				}
				string sss=s;
				if(flg==1) for(int k=0;k<a[0][i].size();k++) sss[j+k]=a[1][i][k];
				if(flg==1)
				{
					int flg1=1;
					for(int k=0;k<s.size();k++) if(sss[k]!=ss[k])
					{
						flg1=0;
						break;
					}
					if(flg1==1) ans++;
				}
			}
		}
		cout <<ans <<'\n';
	}
	return 0;
} 