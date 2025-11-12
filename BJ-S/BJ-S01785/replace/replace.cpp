#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
string s1[200005],s2[200005],t1,t2;
int n,q,ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--)
	{
		ans=0;
		cin>>t1>>t2;
		int len;
		for(int i=0;i<=t1.size();i++)
		{
			for(int j=1;j<=n;j++)
			{
				len=0;
				while(len<s1[j].size() && t1[len+i]==s1[j][len]) len++;
				if(len==s1[j].size())
				{
					string tmp=t1.substr(0,i)+s2[j];
					if(i+s1[j].size()<=t1.size()) tmp=tmp+t1.substr(i+s1[j].size(),t1.size()-i-s1[j].size());
					if(tmp==t2) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}