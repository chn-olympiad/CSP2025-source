#include<bits/stdc++.h>
using namespace std;
int a=[1000000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int num=1;
	for(int i=1;i<n*m;i++)
	{
		if(a[i]>a[0])
		{
			num++;
		}	
	}
	int l=ceil(num*1.0/n);
	cout<<l<<" ";
	int b=num%n;
	if(l%2!=0){
		if(b==0)cout<<n;
		else cout<<b;
	}
	else
	{
		else cout<<n-b+1;
	}
	fclose(stdin);
	fclose(stdout);
		if(b==0)cout<<1;
	return 0;
}

