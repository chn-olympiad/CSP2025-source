#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=101;
int a[N];
bool potato(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[(i-1)*n+j];
			if(i==1&&j==1)
			{
				k=a[(i-1)*n+j];
			}
		}
	}
	sort(a+1,a+n*m+1,potato);
	for(int i=1;i<=n*m;i++)
	{
		//cout<<a[i]<<" ";
		if(a[i]==k)
		{
			k=i;
			//cout<<i<<endl;
			break;
		}
	}
	int l=k%n;
	if(l==0) l=n;
	cout<<ceil(k*1.00/n)<<" ";
	if(int(ceil(k*1.00/n))%2==0) cout<<n-l+1;
	else cout<<l;
	return 0;
}