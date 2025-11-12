#include <bits/stdc++.h>
using namespace std;
int a[1000],n;
int main()
{
	freopen("polygon.in","in","r");
	freopen("polygon.ans","out","c");
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]+a[2]>a[3])
	{
		cout<<1;
	}else{
		cout<<0;
	}
    return 0;
}