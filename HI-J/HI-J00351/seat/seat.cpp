#include<bits/stdc++.h>
using namespace std;
bool ans(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	vector<int> v;
	int n,m,M;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		int a;
		cin>>a;
		if(i==1)M=a;
		v.push_back(a);
	}
	bool p=1;
	int k=0;
	sort(v.begin(),v.end(),ans);
	for(int i=1;i<=m;i++)
	{
		for(int j=(p?(1):(n));(p?(j<=n):(j>0));(p?(j++):(j--)))
		{
			if(v[k++]==M)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
		p=!p;
	}
	return 0;
}
