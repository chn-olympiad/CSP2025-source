#include <iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n,num = 0;
	cin >> n;
	int a[n];
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	int max = a[1];
	for (int i = 1;i<=n;i++)
	{
		if(a[i]>max)
		{
			max = a[i];
		}
		if (a[i]+a[i+1]+a[i+2]/max >= max)
		{
			num++;
		}
		if (a[i]+a[i+1]+a[i+2]+a[i+3]/max >= max)
		{
			num++;
		}
		if (a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]/max >= max)
		{
			num++;
		}
	}
	if (max >=10)
	{
		cout << num;
	}
	else
	{
		cout << num+3v;
	}
	return 0;
 } 
