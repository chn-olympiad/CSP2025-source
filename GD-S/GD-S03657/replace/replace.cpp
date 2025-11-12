#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	vector<pair<string,string> > a;
	vector<pair<string,string> > s;
	int n,q,i;
	string x,y;
	cin>>n>>q;
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		s.push_back({x,y});
	}
	for(i=0;i<q;i++)
	{
		cin>>x>>y;
		a.push_back({x,y});
	}
	for(i=0;i<q;i++)
	{
		int j;
		string r1,r2;
		int maxn=0;
		for(j=0;j<n;j++)
		{
			x=s[j].first;
			y=s[j].second;
			r1=a[i].first;
			r2=a[i].second;
			int sum=r1.find(x);
			int t;
			string r3,r4,r5,r6;
			r3.clear();
			r4.clear();
			r5.clear();
			r6.clear();
			for(t=0;t<sum-1;i++)
			{
				r3=r3+r1[t];
			}
			for(t=sum-1+x.size();t<r1.size();t++)
			{
				r4=r4+r1[t];
			}
			r1=r3+x+r4;
			sum=r2.find(y);
			for(t=0;t<sum-1;i++)
			{
				r5=r5+r2[t];
			}
			for(t=sum-1+x.size();t<r1.size();t++)
			{
				r6=r6+r2[t];
			}
			r2=r5+y+r6;
			if(r1==r2)
			{
				maxn++;
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
}
