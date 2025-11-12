#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],sum,ansx,ansy;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l=n*m;
	cin>>a[1];
	for(int i=2;i<=l;i++)
	{
		cin>>a[i];
		if(a[i]>=a[1])
		{
			sum++;
		}
	}
	sum++;
	if(sum%n==0) ansx=sum/n;
	else ansx=sum/n+1;
	if(ansx%2==1)
	{
		if(sum%n==0) ansy=n;
		else ansy=sum%n;
	}
	else
	{
		if(sum%n==0) ansy=1;
		else ansy=n-sum%n+1;
	}
	cout<<ansx<<" "<<ansy;
	
	
	return 0;
}
