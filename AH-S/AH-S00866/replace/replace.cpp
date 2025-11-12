#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string t1,t2,x,y,t;
int n,q,z,i,j,k;
struct Node
{
    string s1,s2;
}s[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(i=1;i<=n;++i)cin>>s[i].s1>>s[i].s2;
	for(i=1;i<=q;++i)
	{
		cin>>t1>>t2;
		z=0;
		/*
		if(t1.size()==t2.size())
		{
			for(j=1;j<=n;++j)
			{
				for(k=0;k<=t1.size()-s[j].s1.size();++k)
				{
					if(t1.substr(k,s[j].s1.size())==s[j].s1)
					{
						x=t1.substr(0,k);
						y=t1.substr(k+s[j].s1.size(),t1.size()-k-s[j].s1.size());
						t=x+s[j].s2+y;
						if(t==t2)
						{
							z++;
							break;
						}
					}
				}
			}
		}
		*/
		cout<<z<<'\n';
	}
	return 0;
}
