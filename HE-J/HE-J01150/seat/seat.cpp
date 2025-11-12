#include <bits/stdc++.h>
using namespace std;
int a[102];
int x[10][10];
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int num=0;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
		num=max(a[i-1],a[i]);

    } 
    if(n==1 && m==1)
	{
		cout << 1 << " " << 1;
	} 
	
	return 0;
}
