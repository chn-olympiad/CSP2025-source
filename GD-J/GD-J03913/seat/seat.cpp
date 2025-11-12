#include<bits/stdc++.h>
using namespace std;
int n,m,x,k,a[11000];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	if(a[i]==x) {k=i;break;}
	
	if(k%n==0)
	{
		if((k/n)%2==0) cout<<k/n<<" "<<1;
		else cout<<k/n<<" "<<n; 
	}
	else 
	{
		if((k/n)%2==0) cout<<k/n+1<<" "<<k%n;
		else cout<<k/n+1<<" "<<n-(k%n)+1; 
	}
	
	return 0;
}
