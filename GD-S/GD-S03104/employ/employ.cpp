#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string nm;
	cin>>nm;
	int len=nm.size()-1;
	int a[505]={};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<len*n*len*n;
	return 0;
 } 
