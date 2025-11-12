#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	int sum = 0;
	cin >> n >> m;
	for(int i = 1;i <= m*n;i++)
	{
		 cin >> a[i];
	}
	sum = a[1];
	int x = n*m;
	sort(a+1,a+x+1);
	int k = 0;
	for(int i = x;i > 0;i--)
	{
		k++;
		if(a[i] == sum)
			break;
	}
	int num = k%n;
	int l = k/n;
	if(num == 0)
		num = m;
	else if(num != 0)
		l++;
	if(l%2 == 0 && l != 0)
	{
		num = m-num+1;
	}
	if(l == 0)
		l = 1;
	cout << l << " " << num; 
}
