#include<bits/stdc++.h>
using namespace std;
string s[200005][2],quest[200005][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;++i)
	{
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=0;i<q;++i)
	{
		cin>>quest[i][0]>>quest[i][1];
	}
	for(int i=0;i<q;++i)
	{
		int ans=0;
		for(int j=0;j<n;++j)
		{
			if(s[j][0]==quest[i][1])
			{
				++ans;
			}
			if(s[j][1]==quest[i][1])
			{
				++ans;
			}
		}
		for(int j=0;j<n;++j)
		{
			string x;
			int k=0;
			while(s[j][0][k]==quest[j][1][k])
			{
				++k;
				x.push_back(s[j][0][k]);
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


