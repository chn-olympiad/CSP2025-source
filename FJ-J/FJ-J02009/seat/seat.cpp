#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1020],b;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	b=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++)
		if(b==a[i])
		{
			b=i;
			break;
		}
	if((b/m+1)%2==1)
		cout<<b/m+1<<" "<<b%m+1;
	else
		cout<<b/m+1<<" "<<m-b%m;
	return 0;
}
