#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110],x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+m*n+1);
	int h=1,l=1;
	for(int i=m*n;i>=1;i--)
	{
		if(a[i]==x) break;
		if(h<n&&l%2==1) h++;
		else if(h>1&&l%2==0) h--;
		else if(h==1||h==n) l++;
	}
	cout<<l<<" "<<h;
	return 0;
}
