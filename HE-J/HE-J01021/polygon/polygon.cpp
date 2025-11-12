#include<iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n,box=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]>box){
			box=a[i];
		}
	}
	
	int cnt=0;
	if(a[0]+a[1]+a[2]>2*box){
		cnt++;
	}
	cout<<cnt;
	return 0;
}
