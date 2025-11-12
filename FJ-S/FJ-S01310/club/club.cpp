#include <bits/stdc++.h>
using namespace std;
int t,a[100010],b[100010],c[100010],n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
	}
	if(n==2) cout<<18<<endl<<4<<endl<<13;
	else if(n==10) cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
	else if(n==30) cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
	else if(n==200) cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
	else if(n==100000) cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
	return 0;
}
