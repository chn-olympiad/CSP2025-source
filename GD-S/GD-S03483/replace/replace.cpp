#include<iostream>
#include<cstring>
#include<map>
using namespace std;
int n,q;
long long ans;
string s1[200005],s2[200005];
map<string,bool> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf ("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		mp[s1[i]+s2[i]]=true;
	}
	while(q--)
	{
		ans=0;
		string s,t;
		cin>>s>>t;
		if(s.length()!=t.length())
		{
			printf ("0\n");
			continue;
		}
		s=' '+s;
		t=' '+t;
		for (int i=1;i<=n;i++)
			for (int j=1;j+s1[i].length()-1<=s.length();j++)
				if(s.substr(j,s1[i].length())==s1[i]&&t.substr(j,s2[i].length())==s2[i]&&s.substr(1,j-1)==t.substr(1,j-1)&&s.substr(j+s1[i].length(),n-j-s1[i].length()+1)==t.substr(j+s2[i].length(),n-j-s2[i].length()+1))
					ans++;
		printf ("%lld\n",ans);
	}
	return 0;
}
