#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int n,m,a[MAXN];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++) cin>>a[i];
	int xr=a[1],st=0;
	sort(a+1,a+len+1,cmp);
//	for(int i=1;i<=len;i++) cout<<a[i]<<' ';
//	cout<<'\n';
	for(int i=1;i<=len;i++)
		if(a[i]==xr)
		{
			st=i;
			break;
		}
//	cout<<n<<' '<<m<<' '<<xr<<' '<<st<<'\n';
	int x=ceil(st*1.0/n),y=st%n;
//	cout<<x<<' '<<y<<'\n';
	if(y==0) y=n;
	if(x%2==1) cout<<x<<' '<<y<<'\n';
	else cout<<x<<' '<<n-y+1<<'\n';
	return 0;
}
