#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,r;
	r=0;
	string j[10000];
	string h[10000]; 
	cin>>n>>m;
	for(int o=0;o<n;o++)
	{
		cin>>j[o];
	}
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
	}
	for(int p=0;p<m;p++)
	{
		r++;
		if(j[r]==h[r])
		{
			cout<<h[p];
		}
	}
	return 0;
 }
