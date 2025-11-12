#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
int n,m,k;
struct cs
{
	int sum,id;
}a[105];
bool cmp(cs x,cs y)
{
	return x.sum>y.sum;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].sum;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			k=i;
			break;
		}
	}
	cout<<(k+n-1)/n<<" ";
	if((k-1)%(2*n)+1<=n)cout<<(k-1)%(2*n)+1;
	else cout<<2*n-((k-1)%(2*n)+1)+1;
	return 0;
}
