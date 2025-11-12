#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>v;
	for(int i=0;i<n*m;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	int c=v[0];
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	int l=1,u=0,z=0;
	vector<int>x;
	while(x.empty())
	{
		while(u!=n)
		{
			u++;
			if(v[z]==c)
			{
				cout<<l<<" "<<u;
				x.push_back(0);
			}
			z++;
		}
		l++;
		while(u!=1)
		{
			u--;
			if(v[z]==c)
			{
				cout<<l<<" "<<u+1;
				x.push_back(0);
			}
			z++;
		}
		l++;
	}
	
		
}
