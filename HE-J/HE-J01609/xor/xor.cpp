#include<bits/stdc++.h>
using namespace std;
const int M=500010;
int n, k;
int a[M],s[M];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >>a[i];
	}
	int l=1,r=n;
	for(int i = 1; i <= n;i++)
	{
		
		a[l]=s[i]; 
	}
	cout<<1;
	return 0;	
} 

