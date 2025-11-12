//GZ-S00015 贵阳市南明区华麟学校 代钰涵 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10; 
int n,m,ans=0;
string s1[N],s2[N],s3,s4;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>s3>>s4;
	}
	for(int z=1;z<=n;z++)
	{
		int ldl=0;
		for(int i=1;i<=s3.size();i++)
		{
			for(int j=i;j<=s1[z].size();j++)
			{
				if(s3[j]!=s1[z][i]||s4[j]!=s2[z][i]) ldl=1;
			}
		}
		if(ldl==1) ans++;
	}
	cout<<ans;
	return 0;
}
