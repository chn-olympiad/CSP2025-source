#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define of(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define P_B push_back
const int inf=0x3f3f3f3f;
const ll INF=9e18;
const int N=1e5+10;
int q[13][N],len[13],a[N][13],ss[N],ans,cnt_ss,n;
void init()
{
	memset(len,0,sizeof(len));
	memset(ss,0,sizeof(ss));
	ans=0; cnt_ss=0;
}
void sol(int x)
{
	int y,z;
	if(x==1) {y=2; z=3;} if(x==2) {y=1; z=3;} if(x==3) {y=1; z=2;}
	fo(i,1,len[x])
	{
		int now=q[x][i];
//		cout<<"now:"<<now<<endl;//
		int d1=a[now][x]-a[now][y],d2=a[now][x]-a[now][z];
		ss[++cnt_ss]=min(d1,d2);
	}
	sort(ss+1,ss+cnt_ss+1);
	int tot=len[x]-n/2;
	fo(i,1,tot) ans-=ss[i];
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;cin>>T;
	while(T--)
	{
		init();
		cin>>n;
		fo(i,1,n) 
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]) {q[1][++len[1]]=i; ans+=a[i][1]; continue;}
			if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]) {q[2][++len[2]]=i; ans+=a[i][2]; continue;}
			if(a[i][3]>=a[i][1] && a[i][3]>=a[i][2]) {q[3][++len[3]]=i; ans+=a[i][3]; continue;}
		}
		if(len[1]<=n/2 && len[2]<=n/2 && len[3]<=n/2) {cout<<ans<<endl; continue;}
		int tor=0;
		if(len[1]>n/2) tor=1; if(len[2]>n/2) tor=2; if(len[3]>n/2) tor=3;
		sol(tor);
		cout<<ans<<endl;
	}
	return 0;
}
/*
in1:

out1:

*/
