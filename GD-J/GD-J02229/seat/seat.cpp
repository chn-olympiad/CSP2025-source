#include<bits/stdc++.h>
using namespace std;
int s[150],S1,dx,dy;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
	}
	S1=s[1];
	sort(s+1,s+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(s[i]==S1){
			int ii=n*m-i+1;
			dx=(ii-1)/n+1;
			dy=ii%n;
			if(dy==0)dy=n;
			if(dx%2==0)dy=n+1-dy;
			cout<<dx<<' '<<dy;
			break;
		}
	}
	return 0;
}
