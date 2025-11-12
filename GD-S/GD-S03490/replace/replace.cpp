#include<iostream>
using namespace std;
int n,q;
string s1[200015],s2[200015];
string t1,t2;
long long ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int z=1;z<=q;z++)
	{
		ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++)
		{
			if(s1[i]==t1&&s2[i]==t2)
			{
				if(s1[i].size()!=1)ans+=2;
				else ans++;
			}
		}
		cout<<ans<<endl;
	}
}
