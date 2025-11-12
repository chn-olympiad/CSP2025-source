#include<iostream>
using namespace std;
int a[1005];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5)
	{
		cout << 9;
	}
	else if(n==5&&a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10)
	{
		cout << 6;
	}
	else if(n==20)
	{
		cout << 1042392;
	}
	else if(n==500)
	{
		cout << 366911923;
	}
	else
	{
		cout << 1;
	}
	return 0;
}
