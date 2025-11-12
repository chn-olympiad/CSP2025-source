#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long i=1,j=1,p=1;
long long a[101];
long long stua;
struct stu{
	long long x,y;
}b[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;++i)cin>>a[i];
	stua=a[1];
	sort(a+1,a+n*m+1,greater<long long>());
	while(i<=n&&j<=m)
	{
		while(i<=n)
		{
			b[a[p]].x=i;
			b[a[p]].y=j;
			p++;
			i++;
		}
		i=n;
		j++;
		while(i>=1&&j<=m)
		{
			b[a[p]].x=i;
			b[a[p]].y=j;
			p++;
			i--;
		}
		i=1;
		j++;
	}
	cout<<b[stua].y<<" "<<b[stua].x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
