#include<bits/stdc++.h>
using namespace std;
long long m,n,k=0,l=0;
long long a[123];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+m*n);
	for(long long i=1;i<=m*n;i++)
	{
	
		if(k==a[i])
		{
			l=m*n+1-i;
			break;
		}
	}
	cout<<(l+n-1)/n<<" ";
	if(((l+n-1)/n)%2==1)cout<<((l-1)%n)+1;
	else cout<<n-((l+1)%n);
	return 0;
}
