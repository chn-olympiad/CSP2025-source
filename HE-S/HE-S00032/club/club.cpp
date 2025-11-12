#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n;
struct node
{
	int a,b,c;
} q;
vector<node> v;
bool cmpa(node x,node y)
{
	return x.a>y.a;
}
bool cmpb(node x,node y)
{
	return x.b>y.b;
}
bool cmpc(node x,node y)
{
	return x.c>y.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int l=1; l<=t; l++)
	{
		cin>>n;
		int sum=0;
		v.clear();
		for(int i=1; i<=n; i++)
		{
			cin>>q.a>>q.b>>q.c;
			v.push_back(q);
		}
		sort(v.begin(),v.end(),cmpa);
		for(int i=0; i<n/2; i++)
		{
			sum+=v[i].a;
		}
		cout<<sum<<endl;
	}
	return 0;
}
