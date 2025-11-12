//GZ-S00300 毕节七星关东辰实验学校 漆高唤 
#include<bits/stdc++.h>
using namespace std;
unsigned long long n;

int main()
{
	int a[10],n;
	cin>>n;
//	freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	 for(int i=1;i<=5;i++)
	{
		cout<<a[i];
	}
	return 0;
}

