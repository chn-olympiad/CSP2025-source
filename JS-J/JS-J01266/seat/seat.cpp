#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
#define MAXN 105
int n,m,N;
pii a[MAXN];
pii seat[MAXN];
bool cmp(pii x,pii y) {return x.fir>y.fir;}
signed main()
{
	FAST_IO;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;N=n*m;
	for(int i=1;i<=N;i++) cin>>a[i].fir,a[i].sec=i;
	sort(a+1,a+N+1,cmp);
	seat[0]={1,0};
	for(int i=1;i<=N;i++)
	{
		int l=seat[i-1].fir,h=seat[i-1].sec;
		if(l&1)
		{
			h++;
			if(h>n) {h=n;l++;}
		}
		else
		{
			h--;
			if(h<1) {h=1;l++;}
		}
		seat[i]={l,h};
		if(a[i].sec==1) {cout<<l<<' '<<h<<'\n';break;}
	}
	return 0;
}
