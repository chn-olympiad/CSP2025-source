#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[101][2],s3,s4;
int main ()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	while (q--)
	{
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		for (int i=0;i<s1.size();i++) for (int j=i+2;j<s1.size();i++)
		{
			for (int k=i+1;k<j;k++) s3+='0',s4+='0';
			for (int k=0;k<=i;k++) if (s1[k]!=s2[k]) continue;
			for (int k=s1.size();k>=j;k--) if (s1[k]!=s2[k]) continue;
			for (int k=i+1;k<j;k++) s3[k-i-1]=s1[k];
			for (int k=i+1;k<j;k++) s4[k-i-1]=s2[k];
			for (int k=1;k<=n;k++)
			{
				if (s3==s[k][0]&&s4==s[k][1]) 
				{
					ans++;
					break;
				}
			}
			s3.clear();
			s4.clear();
		}
		cout<<ans<<endl;
	}
	return 0;
}
