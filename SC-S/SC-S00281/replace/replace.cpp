#include <bits/stdc++.h>
using namespace std;
string t1[200005],t2[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		cin >> t1[i] >> t2[i];
	}
	string s1,s2;
	cin >> s1 >> s2;
	int cnt=0;
	for(int i=0;i<s1.size();i++)
	{
		for(int j=1;j<=n;j++)
		{
			string s3=s1;
			if(s1.substr(i,t1[j].size())==t1[j])
			{
				int cur=0;
				for(int k=i;k<t1[j].size()+i;k++)
				{
					s3[k]=t2[j][cur];
					cur++;
				}
			}
			if(s3==s2)
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}