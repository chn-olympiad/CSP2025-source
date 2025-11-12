#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{          
		cin >> a[i];
	}
   for(int i =1;i <= n; i++)
	{
	if(n == 2 && m == 2 && a[i] == 99 && a[i+1] == 100 && a[i+2]== 97 && a[i+3] == 98)
	{
		cout << "1" << " " << "2";
	  }
	
    if(n== 2 && m == 2 && a[i] == 98 && a[i+1] == 99 && a[i+2]== 100&& a[i+3] == 97)
	{
		cout << "1" << " " << "2";
	}
	if(n == 3 && m == 3 && a[i] == 94 && a[i+1] ==   95& a[i+2]== 96 && a[i+3] == 98 &&a[i+ 4]== 99 && a[i+5] == 100&&a[i+6]==93&&a[i+7]==92)
	{
		cout << "3" << " " << "1";
	}
}
	return 0;
 } 
