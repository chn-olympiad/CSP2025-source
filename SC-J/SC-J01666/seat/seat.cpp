#include<bits/stdc++.h>
using namespace std;
long long a[10000][10000],b[100000];
long long c,n,m,t=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
    cin>>n>>m;
    cin>>b[1];
    c=b[1];
    for(int i=2;i<=n*m;i++)
    {
    	cin>>b[i];
	}
	int j=1;
	sort(b+1,b+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(b[i]==c)
		{
			c=j;
			break;
		}
		j++;
	}
	if(c%n==0)
	{
		cout<<c/n<<" ";
		t=c/n;		
	}
	else 
	{
		cout<<c/n+1<<" ";
		t=c/n+1;		
	}
	if(t%2==0)
	{
		cout<<n-c%n+1;
	}
	else
	{
		if(c%n==0)
		{
			cout<<n;
			return 0;
		}
		cout<<c%n;
	}
	return 0;	
 } 