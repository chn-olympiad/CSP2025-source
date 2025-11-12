#include<bits/stdc++.h>
using namespace std;
int T,n,a[10005][4],sun,maxx=-1,x,y,z;
void g(int m)
{
	if(m>n)
	{
		if(x>n/2||y>n/2||z>n/2) return;
		maxx=max(sun,maxx);
	}
	x++,
	sun+=a[m][1];
	g(m+1);
	x--,
	sun-=a[m][1],
	y++,
	sun+=a[m][2];
	g(m+1);
	y--,
	sun-=a[m][2],
	z++,
	sun+=a[m][3];
	g(m+1);
	z--,
	sun-=a[m][3];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		g(1);
		cout<<maxx;
		maxx=-1;
	}
	return 0;
}
//@@@    @@@@@  @@@@@
//@  @     @    @    
//@   @    @    @@@@@
//@  @     @    @    
//@@@    @@@@@  @@@@@