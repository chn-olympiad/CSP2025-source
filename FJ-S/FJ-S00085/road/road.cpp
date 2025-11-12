#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,h;
	int city1[1000000],city2[1000000],money[1000000];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>city1[i]>>city2[i]>>money[i];
		h+=money[i];
	}
	cout<<h;
	return 0;
}
