#include<iostream>
#include<algorithm>
using namespace std;
long long a[15][15],n,m,s[105],y;
bool cmp(long long p,long long q)
{
	return p>q;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>y;
	s[1]=y;
	for(long long i=2;i<=m*n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+m*n+1,cmp);
	for(long long i=1;i<=m*n;i++)
	{
		//cout<<s[i];
		if(s[i]==y)
		{
			y=i;
			break;
		}
	}
	//cout<<y;
	long long yy=y/m,x=y%m;
	if(x==0)
	{
		cout<<yy<<' '<<n;
		return 0;
	}
	cout<<yy+1<<' '<<x;
	return 0;
 } 
