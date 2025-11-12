#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,maxx=-14514;
	cin>>n;
	int a[n]={};
	for (int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		if (a[i]>maxx){
			maxx=a[i];
		}
	}
	if (sum>maxx*2){
		cout<<1;
	}
	else {
		cout<<0;
	}
	return 0;
}

