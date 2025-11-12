#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,flag=0;
	cin>>n>>m;
	cin>>a[1];
	flag=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==flag) {
			flag=i;
			break;
		}
	}
	if(flag%n==0)
	{
		cout<<flag/n<<" "<<n;
	}
	else
	{
		cout<<flag/n+1<<" ";
		if((flag/n+1)%2)
			cout<<flag%n;
		else
			cout<<n-flag%n+1;
	}
	return 0;
}
