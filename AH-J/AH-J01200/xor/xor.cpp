#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[3];
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	sort(a+1,a+n+1,cmp);
	cout<<a[1]%a[2];
	return 0;
}
