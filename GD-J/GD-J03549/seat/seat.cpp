#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],cj,wz,r,c; 
bool cmp(int n1,int n2)
{
	return n1>n2;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; // n行数 m  列数 
	cin>>cj;
	a[1]=cj;
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
//	for(int i=1;i<=n*m;i++)
//		cout<<a[i]<<" ";
	for(int i=1;i<=n*m;i++)
		if(a[i]==cj)
			{
				wz=i;
				break;
			}
	c=(wz+n-1)/n;//列 
	r=(wz-1)%m+1;//行
	if(c%2==0)
	r=n-r+1; 
	cout<<c<<" "<<r; 
	return 0;
}
//2 2
//99 100 97 98
