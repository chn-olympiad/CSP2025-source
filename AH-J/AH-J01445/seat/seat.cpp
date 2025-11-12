#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k,i;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
		cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1); 
	for(i=n*m;i>=1;i--)
		if(a[i]==k) 
		{
			i=n*m-i+1;
			break;
		}
	if(((i-1)/n+1)%2==1)
		cout<<(i-1)/n+1<<' '<<((i%n==0)?n:i%n)<<endl;
	else
		cout<<(i-1)/n+1<<' '<<((i%n==0)?1:n-i%n+1)<<endl;
	return 0;
}
