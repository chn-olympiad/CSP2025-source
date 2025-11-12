#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int a[200];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int R;
	cin>>R;
	a[0]=R;
	for(int i=1;i<n*m;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n*m,cmp);
	int b;
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==R)
		{
			b=i;
			break;
		}
	}
	int ansc=0;
	int ansr=0;
	ansc=b/n+1;
	ansr=b%n+1;
	if(!(ansc%2))
	{
		ansr=n-ansr+1;
	}
	cout<<ansc<<" "<<ansr;
	return 0;
}
