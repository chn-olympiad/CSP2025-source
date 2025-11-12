#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sum=1,z,yu;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++) 
	{
		cin>>a[i];
		if(a[i]>a[1]) sum++;
	}
	yu=sum%(n*2);
	z=sum/(n*2);
	if(yu==0) cout<<z*2<<" "<<1;
	else 
	{
		if(yu>n) cout<<z*2+2<<" "<<n-(yu-n)+1;
		else cout<<z*2+1<<" "<<yu;
	}
	return 0;
}


