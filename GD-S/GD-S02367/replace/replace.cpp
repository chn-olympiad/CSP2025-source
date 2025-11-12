#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s[n][2];
	for(int i = 0;i < n;++i)
	cin>>s[i][0]>>s[i][1];
	while(q--)
	{
		int ans = 0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i = 0;i < n;++i)
		{
			string::size_type len1 = t1.find(s[i][0]);
			string::size_type len2 = t2.find(s[i][1]);
			if(len1!=string::npos&&len2!=string::npos)
			{
				string t = t1.substr(0,len1)+s[i][1]+t1.substr(len1+s[i][1].size());
				if(t==t2)++ans;
			}
		}cout<<ans<<endl;
	}
}
