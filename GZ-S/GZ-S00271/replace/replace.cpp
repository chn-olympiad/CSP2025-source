//GZ-S00271 贵阳市第三中学 杨鑫豪 
#include<bits/stdc++.h>
using namespace std;
int n,m,o;
string s1[1000005],s2[1000005],t1,t2;
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
		o=0;
		cin>>t1>>t2;
		for(int j=1;j<=n;j++)
		{
			if(t1==s1[j]&&s2[j]==t2)
			{
				o++;
			}
		}
		cout<<o;
	}
	return 0;
}
