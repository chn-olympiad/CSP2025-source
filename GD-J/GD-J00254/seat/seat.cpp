#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[1005],r,rm;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1,j=n*m;i<=n*m,j>=1;i++,j--)
	{
		if(a[i]==r) {rm=i;break;}
		if(a[j]==r) {rm=j;break;}
	}
	if(rm%n!=0) cout<<rm/n+1<<" ";
	else cout<<rm/n<<" ";
	if(rm%(2*n)==0) cout<<1;
	else
	{
		if(rm%(2*n)<=n) cout<<rm%(2*n);
		if(rm%(2*n)>n) cout<<n+(n-rm%(2*n))+1;
	}
	
	return 0;
}
