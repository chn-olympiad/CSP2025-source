#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i];
	cout<<n<<' '<<m<<endl;
	int score=a[1];
	sort(a+1,a+n*m+1,cmp);
	int rank;
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==score)
		{
			rank=i;
			break;
		}
	}
	int c=(rank-1)/n+1;
	int r=(c%2==1?(rank-1)%n+1:n-(rank-1)%n);
	cout<<c<<' '<<r;
	return 0;
}
