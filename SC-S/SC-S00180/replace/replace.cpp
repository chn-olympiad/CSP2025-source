#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,ans;
struct node
{
	string s1,s2;
}a[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i].s1>>a[i].s2;
	while(q--)
	{
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=-1;i<(int)t1.size();i++)
		{
			for(int j=i+1;j<=(int)t2.size();j++)
			{
				if(i!=-1&&j!=(int)t2.size())
					for(int k=1;k<=n;k++)
						if(a[k].s1==t1.substr(0,i+1)&&a[k].s2==t2.substr(0,i+1))
							ans++;
				if(j-i>1)
					for(int k=1;k<=n;k++)
						if(a[k].s1==t1.substr(i+1,j-i-1)&&a[k].s2==t2.substr(i+1,j-i-1))
							ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/