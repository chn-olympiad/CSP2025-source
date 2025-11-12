#include<bits/stdc++.h>
using namespace std;
int a[100010][3];
vector<int> v[3];
vector<int> vv;
int main2()
{
	v[0].clear();
	v[1].clear();
	v[2].clear();
	vv.clear();
	int n;
	cin>>n;
	int n0=0, n1=0, n2=0;
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
		if (a[i][0]>a[i][1]&&a[i][0]>a[i][2])
		{
			ans+=a[i][0];
			v[0].push_back(i);
			n0++;
		}
		else if (a[i][1]>a[i][2])
		{
			ans+=a[i][1];
			v[1].push_back(i);
			n1++;
		}
		else
		{
			ans+=a[i][2];
			v[2].push_back(i);
			n2++;
		}
	}
	if (n1>n/2)
	{
		swap(v[1], v[0]);
		swap(n1, n0);
	}
	if (n2>n/2)
	{
		swap(v[2], v[0]);
		swap(n2, n0);
	}
	if (n0>n/2)
	{
		for (int i=0;i<n0;i++)
		{
			vv.push_back(2ll*max(max(a[v[0][i]][0], a[v[0][i]][1]), a[v[0][i]][2])-
					a[v[0][i]][0]-a[v[0][i]][1]-a[v[0][i]][2]+
					min(min(a[v[0][i]][0], a[v[0][i]][1]), a[v[0][i]][2]));
		}
		sort(vv.begin(), vv.end());
		for (int i=0;i<n0-n/2;i++)
		{
			ans-=vv[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		main2();
	}
	return 0;
}
