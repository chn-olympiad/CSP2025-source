#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[1005],s2[1005],t1[1005],t2[1005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int r=1;r<=q;r++)
	{
		cin>>t1[r]>>t2[r];
		int len=t1[r].size();
		for(int k=1;k<=n;k++)
		for(int i=0;i<len;i++)
		{
			bool bb=0;
			for(int j=len-1;j>=0;j--)
			{
				if(t1[r][i]!=s1[k][i]||t2[r][j]!=s2[k][j])
					{bb=1;break;}
				bool flag=0;
					for(int t=i;t<=j;t++)
						if(t1[r][t]==s1[k][t]&&t2[r][t]==s2[k][t])
							flag=0;
						else {flag=1;break;}
				if(!flag)
					ans++;
			}if(bb==1)break;}
		cout<<ans<<endl;
	}
	return 0;
}
