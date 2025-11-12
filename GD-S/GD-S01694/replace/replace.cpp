#include<bits/stdc++.h>
using namespace std;
string s1[10086],s2[10086],t1[10086],t2[10086];
int jl1[10086];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>s1[i]>>s2[i];
	for(int i=0;i<q;i++)cin>>t1[i]>>t2[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<s1[i].size();j++)
		{
			if(s1[i][j]=='b')jl1[i]+=j;
			if(s2[i][j]=='b')jl1[i]-=j;
		}
	}
	for(int i=0;i<q;i++)
	{
		int ans=0;
		int jl2=0;
		for(int j=0;j<t1[i].size();j++)
		{
			if(t1[i][j]=='b')jl2+=j;
			if(t2[i][j]=='b')jl2-=j;
		}
		for(int j=0;j<n;j++)
		{
			if(jl2==jl1[j])ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
//ccf对我好一点
 
