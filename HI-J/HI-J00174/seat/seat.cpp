#include<bits/stdc++.h>
using namespace std;


int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+5];
	int num;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+m*n+1);
//	for(int i=1;i<=n*m;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
	int num_nu;
	for(int i=1;a[i]!=num;i++){
		num_nu=i;	
	}
	num_nu=n*m-num_nu;
//	cout<<num_nu<<endl;
	int x=1,y=1;
	bool d=1;	
	for(int i=1;i<num_nu;i++)
	{
		if(d==1) 
			if(x+1<=n) x++;
			else {y++;d=0;}
		else 
			if(x-1>=1) x--;
			else {y++;d=1;}
//		cout<<x<<" "<<y<<" "<<d<<endl;
	}
	cout<<y<<" "<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

