#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	//freopen("polgon.in","r",stdin);
	//freopen("polgon.out","w",stdout);
	int n;
	cin>>n;
	int a[n],b=0,c=0,d=0;
	for(int i=0;i<n;i++){
			cin>>a[i];
	}
	for(int i=0;i<=n;i++)
	{
		for(int i=1;i<=3+i;i++){
			b=a[i]+b;
			if(a[i]>c)c=a[i];
		}
		if(b>c*2)d++;
	}
	cout<<d;
	return 0;
}

