#include <bits/stdc++.h>
using namespace std;
bool q(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
	}
	cout<<(n-2)*(n-1)/2;
	return 0;
} 
