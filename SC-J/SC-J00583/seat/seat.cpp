#include<bits/stdc++.h> 
using namespace std;
int qq[10];
int arr[1000];
int n,m;
int sum=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>arr[i];
		if(arr[i]>=arr[1])
		{
			sum++;
		}
	}
	int a=sum/m;
	int c=sum%m;
	if(c!=0)a++;
	int b=a%2;
	if(b==0)
	{
		if(c==0)
			cout<<a<<" "<<"1";
		else
			cout<<a<<" "<<n+1-c;
	}
	else
	{
		if(c==0)
			cout<<a<<" "<<n;
		else
			cout<<a<<" "<<c;
	}
	return 0;
} 