#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int a[110],s[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	    cin>>a[i],s[a[i]]++;
	for(int i=100;i>=a[1];i--)
	     sum+=s[i];
	int x=(sum-sum%n)/n;
	int y=sum%n;
	if(sum%n==0)y=n;
	if(sum%n!=0)x++;
	if(x%2==0)y=n-sum%n+1;
	cout<<x<<' '<<y;       
    return 0;
}
