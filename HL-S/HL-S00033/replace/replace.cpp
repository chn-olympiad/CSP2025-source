#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e5+5;
string s1[N],s2[N],t1,t2;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)	cin>>s1[i]>>s2[i];
	while(q--)
	{
		int ans=0;
		cin>>t1>>t2;
//		cout<<t1<<" "<<t2<<"\n"; 
		if(t1.size()!=t2.size())	cout<<"0\n";
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(s1[i].size()>t1.size())	continue;
				for(int j=0;j<=t1.size()-s1[i].size();j++)
				{
					string a1="",a2="";
					for(int k=0;k<j;k++)	a1+=t1[k];
					for(int k=0;k<s1[i].size();k++)	a1+=s1[i][k];
					for(int k=j+s1[i].size();k<t1.size();k++)	a1+=t1[k];
//					cout<<a1<<"\n";
					if(a1!=t1)	continue;
					for(int k=0;k<j;k++)	a2+=t1[k];
					for(int k=0;k<s2[i].size();k++)	a2+=s2[i][k];
					for(int k=j+s2[i].size();k<t1.size();k++)	a2+=t1[k];
//					cout<<a1<<" "<<a2<<"\n";
					if(a2==t2)	ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
//10pts
