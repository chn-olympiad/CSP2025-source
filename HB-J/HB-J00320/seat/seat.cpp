#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,u,r,cnt=0,x=1,y=1;
	cin>>n>>m>>r;
	for(int i=1;i<n*m;i++)
		cin>>u,cnt+=u>r;
	while(cnt--)
		if(x!=n&&y%2)
			x++;
		else if(x!=1&&y%2==0)
			x--;
		else y++;
	cout<<y<<' '<<x<<'\n';
	return 0;
}