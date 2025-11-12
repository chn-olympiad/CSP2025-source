#include<bits\stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int l=s[i][0].length();
			for(int j=0;j+l<=s1.length();j++)
			{
				if(s1.substr(j,l)==s[i][0])
				{
					string ss1=s1.substr(0,j);
					string ss2=s1.substr(j+l,s1.length()-j-l);
					if(ss1+s[i][1]+ss2==s2)
						ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
