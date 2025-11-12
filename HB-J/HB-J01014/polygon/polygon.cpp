#include<bits/stdc++.h>
using namespace std;
const int N=1005;
long long n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	long long t=1;
	for(int i=2;i<=n;i++)
		t*=i;
	cout << t-6;
	return 0;
}
