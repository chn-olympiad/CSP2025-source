#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define ex exit(0);
#define pii pair<int,int> 
#define sinzo return 
#define code 0 
using namespace std;
const int N=2e6+10;
const int mod=998244353;
int n,m,k,cnt,sum,rp;
int a[N],b[N],c[N],dp[N][2];
map<int,bool>vis;
int qpl[6000]={1};
void init()
{
	int rp=1;
	for(int i=1;i<=5010;i++)
	{
		rp*=2;
		rp%=mod;
		qpl[i]=rp-1;
	}
}
void dfs(int x,int la,int mx,int sum)
{
	if(la==n)
	{
		if(sum>mx*2)
		{
			rp++;
			if(rp>=mod)rp=0;
			
		}
		return;
	}
	for(int i=la+1;i<=n;i++)
	{
		dfs(x+1,i,max(mx,a[i]),sum+a[i]);
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	init();
	int luogu=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)luogu=0;
	}
	sort(a+1,a+1+n);
	if(n<=3)
	{
		if(a[1]+a[2]>a[3])rp++;
		cout<<rp;
		ex;
	}
	if(luogu==1)
	{
		cout<<qpl[n];
		ex;
	}
	dfs(1,0,0,0);
	cout<<rp;
	sinzo code;
} 
/*
5
2 2 3 8 10

5
1 2 3 4 5

*/
/**
 *
 * 假了
 * 预计100+100+75+(40+28)=323
 * QWQ 没有J1=了
 * 技不如人，受着！
 * 
 * #include<windows.h>
 * //	freopen("polygon.in ",r,stdin);
 * //	feroenp("polygon.out ",w,stdout);
 * //	freonpe("polygon.in ","r",stdin);
 * //	freoepn("polygon.out ","w",stdout);
 * //	freopen("polygon.in ","r","stdin");
 * //	freopen("polygon.out ","w","stdout");
 * mian itn sacc srot reutrn 
 * luogu 873466 sinzo 
 * I can do anything!!!
 * 
/*/