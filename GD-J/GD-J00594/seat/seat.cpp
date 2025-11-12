#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int a[105],p;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	p=a[1];

		
	sort(a+1,a+n*m+1);
	p=lower_bound(a+1,a+n*m+1,p)-a,p=n*m-p+1;
	
	int c=(p-1)/n+1,r=0;
	
	r=p-(c-1)*n;
	if(c%2==0) r=m-r+1;
	
	cout<<c<<" "<<r;
	
	return 0;
}
