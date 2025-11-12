#include<bits/stdc++.h>
using namespace std;

int n,m,k,cnt=1;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<n*m;i++)
	{
		int x;
		cin>>x;
		if(x>k) cnt++;
	}
	int c=(cnt+n-1)/n;
	int r=cnt%n;
	if(r==0) r=n;
	if(c%2==0) r=n-r+1;
	cout<<c<<' '<<r<<endl;
	return 0;
}
