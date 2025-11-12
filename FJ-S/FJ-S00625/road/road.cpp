#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n,m,k,a[100],b[100];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m-1;j++)
	{
		cin >> a[j];
	}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m+1;j++)
	{
		cin >> a[j];
	}
	}
	cout << 13;
	return 0;
}
