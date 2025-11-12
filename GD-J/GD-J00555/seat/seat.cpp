#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[105],st;
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];st=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==st){st=i;break;}
	cout<<(st-1)/n+1<<' '<<(((st-1)/n+1)%2==1?st-(st-1)/n*n:n+1-(st-(st-1)/n*n));
	return 0;
}

