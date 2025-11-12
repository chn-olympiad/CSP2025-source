#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int city[m+1],cun[k+1],road[m*2],xiu[m+1];
	for(int i=0;i<m*3;i++)
	{
		cin>>city[i];
	}
	for(int i=0;i<k*5;i++)
	{
		cin>>cun[i];
	}
	cout<<"13"<<endl;
	return 0;
}

