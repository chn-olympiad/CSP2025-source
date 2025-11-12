#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200010][2];
int len[200010];
main()
{
	ifstream cin("replace.in",ios::in);
	ofstream cout("replace.out",ios::out);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1],len[i]=s[i][0].size();
	for(int i=1;i<=q;i++)
	{
		string l1,l2;
		cin>>l1>>l2;
		int l=l1.size();
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			int ii=0;
			for(;ii<l;ii++)
			{
				int now=l1.find(s[j][0],ii);
				if(now==-1) break;
				string nex=l1;
				for(int it=now,k=0;k<len[j];k++,it++)
					nex[it]=s[j][1][k];
				if(nex==l2)
				{
					ans++;
					break;
				}
//				if(l2.substr(now,len[j])==s[j][1]) ans++;
				ii=now;
				if(ii>=l) break;
			}
		}
		cout<<ans<<endl;
	}
}
