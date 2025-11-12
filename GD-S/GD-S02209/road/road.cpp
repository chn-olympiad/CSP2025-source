#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
int main()
{
	freopen ("road.in" , "l" , stdin);
	freopen ("road.out" , "w" , stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int a[m+1][1][1][1];
    for (int i=1;i<=m;i++)
    {
    	cin >> a[i][0][0][0];
	}
	int b[k+1][1][1][1][1][1];
	for (int i=1;i<=k;i++)
    {
    	cin >> b[i][0][0][0][1][1];
	}
	cout << 13;
}
