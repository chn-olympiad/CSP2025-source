#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	int num,p;
}a[105];
bool cmp(node x,node y)
{
	return x.num>y.num;
}
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].num;
		a[i].p=i;
	}
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].p==1)
		{
			if(((int)ceil(i/(double)n))%2==1) cout<<(int)ceil(i/(double)n)<<' '<<(i%n==0?n:i%n);
			else cout<<(int)ceil(i/(double)n)<<' '<<n-(i%n)+1;
			return 0; 
		}
	}
	return 0;
}

