#include<bits/stdc++.h>
using namespace std;


int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m; //列数，行数  
	cin>>n>>m;
	int fosz=m*n;
	multiset<int>v;
	int r;
	cin>>r;
	v.insert(r);
	for(int i=1;i<fosz;i++)
	{
		int a;
		cin>>a;
		v.insert(a);
	}
	vector<int>p(fosz);
	int i=fosz-1;
	for(auto t:v)
	{
		p[i]=t;
		i--;
	}
	
	i=0;
	for(int y=1;y<=n;y++)
	{
		if(y%2==1)
		{
			for(int x=1;x<=m;x++)
			{
//				cout<<y<<" "<<x<<" "<<p[i]<<endl;
				if(p[i]==r)
				{
					cout<<y<<" "<<x;
					return 0;
				}
				i++;
			}
		}
		else
		{
			for(int x=m;x>=1;x--)
			{
//				cout<<y<<" "<<x<<" "<<p[i]<<endl;
				if(p[i]==r)
				{
					cout<<y<<" "<<x;
					return 0;
				}
				i++;
			}
		}
	}
	
	
	
	
	return 0;
}
