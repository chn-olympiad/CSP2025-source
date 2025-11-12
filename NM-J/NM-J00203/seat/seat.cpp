#include<bits/stdc++.h>
using namespace std;
//int a[20][20];
int a[200];
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

	int xiaor=a[1];
	sort(a+1,a+n*m+1);
//	reverse(a+1,a+n*m+1);
	int l=1;
	int r=n*m;
	int mid=(l+r)/2;
	int x=0;
	for(int i=l;i<=r;i++)
	{

		if(a[i]==xiaor)
		{
			x=i;
			break;
		}

	}

	//chuli
	int lie;
	int x1=n*m-x+1;
	if(x1%n==0){
		lie=x1/n;
	}else{
		lie=x1/n+1;
	}

//	int lie1=n-lie+1;
	cout<<lie<<" ";
	int hang;

	if(x1%n==0)hang=m;
	else hang=x1%n;

	if(lie%2==0)cout<<1+m-hang;
	else cout<<hang;
//	if(lie%2==1)

}
