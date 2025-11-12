#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,s=0,k=0;
	int a[100005],b[100005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{	
		cin>>a[i];
		s+=a[i];
	}
	if(n==3)
	{
		sort(a+1,a+n+1);
		if(a[n]*2<s) cout<<1;
		else cout<<0;
	}
	else if(n==4)
	{
		sort(a+1,a+n+1);
		if(a[n]*2<s) k++;
		for(int i=1;i<=n;i++)
		{	
			for(int i=1;i<=n;i++) b[i]=a[i];
			int f=s-a[i];
			b[i]=0;
			sort(b+1,b+n+1);
			if(b[n]*2<f) k+=1;
		}
		cout<<k;
	}
	else cout<<0;
	return 0;
}
