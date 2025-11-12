#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,rank,p;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	p=a[1];
	sort(a,a+n*m);
	rank=n*m-(lower_bound(a,a+n*m,p)-a);
	int col=rank/n,row=rank%n;
	if(col&1)
		row=n-row-1;
	cout<<col+1<<' '<<row+1;
}
