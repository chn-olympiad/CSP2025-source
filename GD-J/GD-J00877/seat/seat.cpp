#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
bool cmp(int a,int b)
{
	return a>b;
}
int R,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
	{
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1; i<=n*m; i++)
	{
		if(R==a[i])
		{
			num=i;
			break;
		}
	}
	int l=num/n+(num%n!=0);
	int r;
	if(l%2==1) r=(num-(l-1)*n);
	else r=n-(num-(l-1)*n)+1;
	cout<<l<<" "<<r;
	
	return 0;
}
