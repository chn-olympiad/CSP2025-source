#include <bits/stdc++.h>
using namespace std;
long long arr[103];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int hang,lie;
	cin >> n >> m;
	int p = n * m;
	int k;
	for (int i = 1;i <= p;i++) cin >> arr[i];
	long long flag = arr[1];
	sort(arr+1,arr+1+p,cmp);
	for (int i = 1;i <= p;i++)
	{
		if (arr[i] == flag) k = i;
	}
	if (k % n != 0) 
	{
		lie = k / n + 1;
	}
	else 
	{
		lie = k / n;
	}
	if (lie % 2 == 0)
	{
		hang = lie * n - k + 1;
	}
	else 
	{
		hang = n + k - lie * n;
	}
	cout << lie << " " <<hang;
	return 0;
}
