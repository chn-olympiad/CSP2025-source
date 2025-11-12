#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int a = n*m;
	cin >> a;
	int i = 1;
	while(0)
	{
		if(a[i-1]<a[i])
		{
			a[i-1]=a[i];
			i++;
		}
		else
		{
			i++;
		}
		if(a[i+1]=0)
		{
			break;
		}
	}
	int s[n][m];
	int s=a;
	cout << s[n][m];
	return 0;	
} 


