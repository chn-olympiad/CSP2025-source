#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,x;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		if(i==1)
			cin>>a[1],a[0]=a[1];
		else
			cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==a[0])
		{
			x=i;
			break;
		}
	cout<<(x+n-1)/n<<" "<<(((x+n-1)/n)%2==1?(x-1)%n+1:n-(x-1)%n);
}
