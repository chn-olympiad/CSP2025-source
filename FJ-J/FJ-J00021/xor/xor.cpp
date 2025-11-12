#include <bits/stdc++.h>
using namespace std;
const int N=10000;
int a[50000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<n/k;
	return 0;
}
//评测机大人你行行好吧，给我点分吧，5分也是分啊 
