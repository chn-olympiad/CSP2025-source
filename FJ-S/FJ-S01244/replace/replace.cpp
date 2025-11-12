#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c=n+m;
	string a,b;
	for(int i=1;i<=c;i++)
	{
		cin>>a>>b;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<rand()%100<<"\n";
	}
	return 0;
} 
