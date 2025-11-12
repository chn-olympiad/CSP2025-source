#include<bits/stdc++.h>
using namespace std;
int a[105],n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1);
	int wei=lower_bound(a+1,a+n*m+1,r)-a;
	wei=n*m-wei+1;
	int lie=2*(wei/(n*2))+1,pai=wei%(n*2);
	if(pai>n)
	{
		pai=2*n-pai+1;
		lie+=1;
	}
	cout<<lie<<" "<<pai;
	return 0;
}
