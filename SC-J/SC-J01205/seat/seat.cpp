#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,hang,lie,i,xr,k;
	int a[1000];
	cin>>n>>m;//n表示行数；m表示列数 
	for(i=0;i<n*m;i++)
	{
		cin>>a[i];
		xr=a[0];
	}
	sort(a,a+n*m);
	reverse(a,a+n*m);
	for(i=0;i<n*m;i++)
	{
//		cout<<a[i]<<" ";
		if(xr==a[i])
		{
			k=i;
		}
	}
	k++;
//	cout<<xr<<" ";
//cout<<k<<endl;
	if(k%n==0)
	{
		lie=k/n;
	}
	else 
	{
		lie=k/n+1;
	}
	cout<<lie<<" "; 
	if(lie%2==1)
	{
		hang=k-(lie-1)*n;
	} 
	else
	{
		hang=n-(k-(lie-1)*n)+1;
	}
	cout<<hang<<endl;
	return 0;
}