#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s[N],t[N],o[N];
int ans=0;
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>s[i];
	for(int i=1;i<=q;i++)
	cin>>t[i]>>o[i];
	for(int ii=1;ii<=q;ii++)
	{
		for(int i=1;i<=n;i++)
		{
			int k=s[i].size();
			int uu=t[ii].size();
			for(int j=0;j<=n-k;j++)
			{
				string ss;
				for(int kk=j;kk<k;kk++)
				ss+=t[ii][kk];
				if(ss==s[i])
				{
					string u=t[ii].substr(0,j);
					u+=ss;
					u+=t[ii].substr(k,uu);
					if(u==o[ii])
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//犯大吴疆土者，盛必击而破之! 
