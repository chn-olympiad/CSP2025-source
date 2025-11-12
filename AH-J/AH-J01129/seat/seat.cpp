#include<bits/stdc++.h>
using namespace std;
int n,m,r,x,sum;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>m>>n;
	cin>>r;
	for(int i=2;i<=n*m;i++)
	{
		cin>>x;
		if(x>r)
		{
		   sum++;
		}
	}
	cout<<sum/m+1<<" ";
	if((sum/m+1)%2==1)
	{
	   cout<<sum%n+1;
	}
	else
	{
		cout<<n-(sum%n);
	}
	return 0;
}
