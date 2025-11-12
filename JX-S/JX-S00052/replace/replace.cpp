#include<bits/stdc++.h>
using namespace std;
map <string,string> m;
string s,w;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;cin>>s1>>s2;m[s1]=s2;
	}
	while(q--)
	{
		int ans=0;
		cin>>s>>w;
		for(int i=0;i<s.size()-1;i++)
		{
			for(int j=i;j<s.size();j++)
			{
				string s1,s2,s3;
				s1=s2=s3="";
				for(int k=0;k<i;k++) s1+=s[k];
				for(int k=i;k<=j;k++) s2+=s[k];
				for(int k=j+1;k<s.size();k++) s3+=s[k];
				s2=m[s2];
				if(s1+s2+s3==w) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
