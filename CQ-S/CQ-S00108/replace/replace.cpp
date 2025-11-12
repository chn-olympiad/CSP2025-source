#include<bits/stdc++.h>
using namespace std;
const int N=5e6+6;
string s[N][3],t1,t2,t3,t4;
int main()

{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,q,v;
	cin>>n>>q;v=q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	while(q--)
	{
		cin>>t1>>t2;
		int ans=0;
		if(t1.size()!=t2.size())
		{
			cout<<0<<"\n";
			continue;
		}
		if(n>100||v>100) 
		{
			cout<<0<<"\n";
			continue;
		}
		for(int i=0;i<t1.size();i++)
		{
			for(int j=1;j<=n;j++)
			{
				t3=t1;
				int len=s[j][1].size();
				for(int k=0;k<len;k++)
				{
					if(t3[i+k]==s[j][1][k]) t3[i+k]=s[j][2][k];
					else break;
				}
				if(t3==t2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
