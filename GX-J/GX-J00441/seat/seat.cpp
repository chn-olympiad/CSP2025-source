#include<bits/stdc++.h>
using namespace std;

int n, m, ans=1;
int x, y;
int cj[100+5];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;//n 行  m 列
	for(int i=0;i<n*m;i++)//cin cj
	{
		cin>>cj[i];
	}
	for(int i=1;i<n*m;i++)//than cj
	{
		if( cj[0]<cj[i] )ans++;	//ans --> than win
	}//cout<<"ans="<<ans<<endl;//ce shi
	
	
//y 行  x 列
	if( ans%n==0 )
	{
		y=n;
		x=ans/n;
	}
	if( ans%n!=0 )
	{
		y=ans%n;
		x=(ans-y)/n+1;
	}
	
	
//cout  ans
	if(x%2==0)//ni 'sky'
	{
		y=n+1-y;
		cout<<x<<" "<<y;
		return 0;
	}
	if(x%2==1)//chang gui
	{
		cout<<x<<" "<<y;
		return 0;
	}
	
	//wan yi ne
	return 0;
}
