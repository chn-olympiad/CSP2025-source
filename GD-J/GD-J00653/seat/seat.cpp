#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],w=0,r=0;
int main(){
	cin>>n>>m;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	w=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(w==a[i])
		{
			r=n*m-i+1;
		}
	}
	if(((r-1)/n+1)%2==0)
	{
		cout<<(r-1)/n+1<<" "<<n-((r-1)%n+1)+1;
		return 0;
	}
	else
	{
		cout<<(r-1)/n+1<<" "<<((r-1)%n)+1;
	}
	return 0;
} 
