#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[m*n+5];
	for(int i = 1;i <= m*n;i++)
	{
		cin >> a[i];
	}
	int sc1 = a[1];
	sort(a,a+(m*n+1),cmp);
	int tmp = 0;
	for(int i = 1;i <= m*n;i++)
	{
		if(a[i] = sc1)
		{
			tmp = i;
		}
	}
	if(m == 1&& n==1)
	{
		cout << 1 << " " << 1;
		return 0; 
	}
	else if(n == 1)
	{
		cout << 1 <<" " << tmp; 
		return 0;	
	 } 
	 else if(m == 1)
	 {
	 	cout << tmp <<" " << 1;
	 	return 0;
	 }

	return 0;
}

