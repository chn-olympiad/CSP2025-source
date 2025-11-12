#include<bits/stdc++.h>
using namespace std;
int n,q,pos,ans;
string s1[200010],s2[200010],as1,as2;
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
		cin>>as1>>as2;
		ans=0;
		for(int j=0;j<n;j++)
		{
			while(1)
			{
				pos=as1.find(s1[i]);
				if(pos!=as1.size())
				{
					string ss=as1;
					ss.erase(pos,s1[i].size());
					ss.insert(pos,s2[i]);
					if(ss==as2)ans++;
				}
				else break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
