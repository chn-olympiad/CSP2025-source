#include <bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			r=i;
		}
	}
	int g=r/m+1;
	if(r<=n) cout<<g-1<<" "<<r<<endl;
	else if(g%2==0) cout<<g<<" "<<n-g%n<<endl;
	else cout<<g<<" "<<g%n+1<<endl;
	return 0;
} 
