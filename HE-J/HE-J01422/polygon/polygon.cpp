#include<bits/stdc++.h>
using namespace std;
#define QWQ return 0
int main()
{
	int n;
	cin>>n;
	int amax=0,a[n+1],ah=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ah=ah+a[i];
		if(amax<a[i])
			amax=a[i];
	}
	cout<<1;
	QWQ;
}
