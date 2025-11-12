#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
string t1,t2;
int ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++)
	{
		ans=0;
		cin>>t1>>t2;
		string cnt,ctn;
		for(int j=0;j<=t1.size();j++)
		{
			if(t1[j]==t2[j])
			{
				continue;
			}else
			{
				cnt+=t1[j];
				ctn+=t2[j];
			}
		}
		for(int j=0;j<n;j++)
		{
			if(cnt==s1[j] && ctn==s2[j])
			{
				ans++;
				continue;
			}
			if(t1==s1[j] && t2==s2[j])
			{
				ans++;
				continue;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
