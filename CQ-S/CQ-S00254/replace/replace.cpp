#include<bits/stdc++.h>
using namespace std;
string a[200005],b[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		bool tmp=0;
		int l=0,r=-1;
		for(int i=0;i<t1.size();i++)
		{
			if(t1[i]!=t2[i])
			{
				if(!tmp)
				{
					l=i;
				}
				r=i;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			int y=t1.find(a[i]);
			if(y>=0)
			{
				if(y>l||y+a[i].size()-1<r)
				{
					continue;
				}
				if(t2.substr(y,a[i].size())==b[i])
				{
					++cnt;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
//10~30pts
