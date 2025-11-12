#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1]={};
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int r[2];
	r[0]=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r[0])
		{
			r[1]=i;
			break;
		}
	}
	int x=r[1]/n,y=r[1]%n;
//	cout<<x<<" "<<y<<endl;
	if(y)
	{
		x++;
	}
	if(y==0)
	{
		y=n;
	}
	if(x%2==0)
	{
		y=n-y+1;
	}
//	for(int i=1;i<=n*m;i++)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//	cout<<r[0]<<" "<<r[1]<<endl;
	cout<<x<<" "<<y<<endl;
	return 0;
}
