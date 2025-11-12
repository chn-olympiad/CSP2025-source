#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[222];
int b[15][15];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		t=a[1];
	}
	sort(a+1,a+n*m+1);
	int c,r;//RµÄÐÐÁÐ 
	for(int i=n*m;i>=1;i--)
	{
		int x=n*m-i+1;
		if(a[i]==t){
			if(x%2==0)
			{
				c=x/m;
				}	
			else if(x%2==1)
			{
				c=x/m+1;
			}
			if(c%2==0)
			{
				r=x%n+1;
			}
			else if(c%2==1)
			{
				r=c%n+1;
			}
			cout<<c<<" "<<r<<endl;
		}

	}
	return 0;
}
