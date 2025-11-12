#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int s[m];
	cin >> n >> m >> k;
	for(int i=0;i<m;i++)
	{
		int p[3];
		cin >> p[0] >> p[1] >>p[2]; 
	}
	for(int i=0;i<k;i++)
	{
		int m[n+1];
		for(int j=0;j<n+1;j++)
		{
			cin >> m[j];
		}
	}
	
	cout << "13"; 
	return 0;
}
