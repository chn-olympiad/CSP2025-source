#include<bits/stdc++.h>
#define int long long
using namespace std;
bool Mst;
const int N=1e5+10;
int t,n,a[N][5],d[N];
int cnt[5],b[N];
int c[N],lc;

bool Med;
signed main()
{
//	cerr<<"Memory:"<<(&Med-&Mst)/1048576.0<<" MiB\n";
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=0;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int mx=-1,mxp=0,sx=-1;
			for(int j=1;j<=3;j++)
			{
				if(a[i][j]>mx)
				{
					sx=mx,mxp=j,mx=a[i][j];
				}
				else if(a[i][j]>sx) sx=a[i][j];
			}
			cnt[mxp]++;
			ans+=mx;
			d[i]=mxp;
			b[i]=mx-sx;
		}
		int pos=0;
		for(int i=1;i<=3;i++)
		{
			if(cnt[i]*2>n)
			{
				pos=i;
				break;
			}
		}
		if(pos)
		{
			lc=0;
			for(int i=1;i<=n;i++)
			{
				if(d[i]==pos)
				{
					c[++lc]=b[i];
				}
			}
			sort(c+1,c+1+lc);
			int l=1;
			while(cnt[pos]*2>n)
			{
				cnt[pos]--;
				ans-=c[l];
				l++;
			}
		}
		cout<<ans<<endl;
	}
}
/*
club

g++ club.cpp -o club.exe
g++ check.cpp -o check.exe
./club.exe
./check.exe

1
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042

*/
