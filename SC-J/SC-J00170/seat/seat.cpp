#include<bits/stdc++.h>
using namespace std;
struct node
{
	int now;
	int id;
}a[10010];
int n,m;
bool cmp(node x,node y)
{
	return x.now>y.now;
}
int tmp;
int l,r;
int main(void)
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;++i)
	{
		cin >> a[i].now;
		a[i].id=i;
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;++i)
	{
		if(a[i].id==1)
		{
			tmp=i;
			break;
		}
	}
	l=(tmp/n)+1;
	r=tmp%n;
	if(r==0)
	{
		r=n;
		--l;
	}
//	for(int i=1;i<=n*m;++i)cout << a[i].now << ' ';
	if(l%2==1)
	{
		cout << l << ' ' << r;
		return 0;
	}
	cout << l << ' ' << (n-r+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}