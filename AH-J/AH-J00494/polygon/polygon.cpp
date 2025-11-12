#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5005];
long long q[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cout<<(1+(n-3+1))*(n-2)/2;
	return 0;
}
