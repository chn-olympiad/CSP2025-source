#include<bits/stdc++.h>
using namespace std;
long long a[1001],n;
int main()
{
	freopen("polydon.in","r",stdin);
	freopen("polydon.out","w",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<*max_element(a,a+n);
	return 0;
}
