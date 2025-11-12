#include<bits/stdc++.h>
#define int long long
#define q n*m
using namespace std;
int n,m,usss,cnt,nowi=1,nowj=0,nexxt=1;
int a[114];
bool cmp(int x,int y){return x>y;}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cnt=q;
	for(int i=1;i<=q;i++) scanf("%lld",&a[i]);
	usss=a[1];
	sort(a+1,a+q+1,cmp);
	for(int i=1;i<=q;i++)
	{
		nowj+=nexxt;
		if(nowj==n+1)
		{
			nowi++;
			nowj=n;
			nexxt=-1;
		}
		if(nowj==0)
		{
			nowi++;
			nowj=1;
			nexxt=1;
		}
		if(a[i]==usss) 
		{
			printf("%lld %lld",nowi,nowj);
			return 0;
		}
	}
	return 0;
}