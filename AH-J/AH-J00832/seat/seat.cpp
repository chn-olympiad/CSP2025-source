#include<bits/stdc++.h>
using namespace std;

const int N=105;
int n,m,cnt,mark;
int a[N],x[N],y[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	mark=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			cnt++;
			if(i%2) x[a[cnt]]=i,y[a[cnt]]=j;
			else x[a[cnt]]=i,y[a[cnt]]=n-j+1;
		}
	cout<<x[mark]<<" "<<y[mark];
	return 0;
}

