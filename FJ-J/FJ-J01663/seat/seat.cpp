#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,cnt;
bool cmp(int q,int h){return q>h;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==cnt)
		{
			int x=(i-1)/n+1,y;
			if(x&1) y=(i-1)%n+1;
			else y=n-(i-1)%n;
			cout<<x<<" "<<y;
			return 0;
		}
	}
	return 0;
}
