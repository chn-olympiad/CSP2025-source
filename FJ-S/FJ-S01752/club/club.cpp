#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=201,MOD=0,inf=0x3f3f3f3f;
int a[N][4],f[N][N][N];struct u{int a,b;}l[N];
bool cmp(u a,u b) {return a.a<b.a;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--)
	{
		int n,e=0,rr=1;cin>>n;memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][3]!=0) rr=0;
		}
		if(rr)
		{
			for(int i=1;i<=n;i++) l[i].a=a[i][1]-a[i][2],l[i].b=i;
			sort(l+1,l+1+n,cmp);
			for(int i=1;i<=n/2;i++) e+=a[l[i].b][2];
			for(int i=n/2+1;i<=n;i++) e+=a[l[i].b][1];
			cout<<e<<endl;continue;
		}
		for(int i=1;i<=n;i++)
			for(int x=min(i,n/2);x>=0;x--)
				for(int y=min(i-x,n/2),z=i-x-y;y>=0 && z<=n/2;y--,z=i-x-y)
				{
					if(z) f[i][x][y]=max(f[i][x][y],f[i-1][x][y]+a[i][3]);
					if(x) f[i][x][y]=max(f[i][x][y],f[i-1][x-1][y]+a[i][1]);
					if(y) f[i][x][y]=max(f[i][x][y],f[i-1][x][y-1]+a[i][2]);
				}
		for(int x=n/2;x>=0;x--)
			for(int y=n/2;y>=0;y--) e=max(e,f[n][x][y]);
		cout<<e<<endl;
	}
	return 0;
}
