#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int n,q,ans;
string t,tt;

struct Node{
	string s,ss;
}zu[N];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>zu[i].s>>zu[i].ss;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t>>tt;
		int tl=t.length();
		ans=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<tl;k++)
			{
				string c=zu[i].s,cc=zu[i].ss;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
