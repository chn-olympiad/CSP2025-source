#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,cnt=0,a;
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<n*m;i++)
	{
		cin>>a;
		if(a>x)cnt++;
	}
	if((cnt/m)%2==1)cout<<cnt/m+1<<" "<<m-cnt%m;
	else cout<<cnt/m+1<<" "<<cnt%m+1;
	return 0;
}
