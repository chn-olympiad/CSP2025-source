#include<bits/stdc++.h>
using namespace std;
struct i
{
	int f,g;
};
bool cmp(i a,i b)
{
	return a.g>b.g;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	i a[111];
	cin>>n>>m;
	for(int c=1;c<=n*m;c++)
	{
		cin>>a[c].g;
		a[c].f=c;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int c=1;c<=n*m;c++)
	{
		if(a[c].f==1)
		{
			c--;
			if((c/n)%2) cout<<c/n+1<<' '<<n-(c%n);
			else cout<<c/n+1<<' '<<c%n+1;
			return 0;
		}
	}
	return 0;
}
