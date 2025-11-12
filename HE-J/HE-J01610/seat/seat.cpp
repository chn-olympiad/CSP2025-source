#include<bits/stdc++.h>
using namespace std;
int n[1000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,sum,k;
	cin>>a>>b;
	sum=1;
	for(int i=1;i<=a*b;i++)
	{
	cin>>n[i];
	}
	for(int i=2;i<=b*a;i++)
	{
	 if(n[1]<n[i])
	 sum=sum+1;
	}
	if(sum<=a)
	cout<<"1"<<sum;
	else	if(sum%a!=0&&b%2==0)
	cout<<sum/a+1<<" "<<a;
	else if(sum%a!=0&&b%2!=0)
	cout<<sum/a+1<<" "<<7%a;
	else if(sum%a==0&&b%2!=0)
	cout<<sum/a<<" "<<"1";
	else if(sum%a==0&&b%2==0)
	cout<<sum/a<<" "<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
