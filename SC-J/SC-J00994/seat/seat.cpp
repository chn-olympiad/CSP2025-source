#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+5;
int n,m,x;
int a[N],cnt,gra,sum;
bool cmp(int x,int y){
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=n*m;
	for(int i=1;i<=x;i++)
		cin>>a[i];
	gra=a[1];
	sort(a+1,a+x+1,cmp);
	for(int i=1;i<=x;i++)
		if(a[i]==gra)
		{
			sum=i;
			break;
		}
	int ix=1,iy=1,fx=0;
	cnt=1;
	while(1)
	{
		if(cnt==sum)
		{
			cout<<iy<<" "<<ix;
			break;
		}
		if(fx==0 && ix==n && iy==m)	break;
		if(fx==1 && ix==1 && iy==m)	break;
		if(fx==0 && ix+1>n)
		{
			iy++,fx=1,cnt++;
			continue;
		}
		if(fx==1 && ix-1<1)
		{
			iy++,fx=0,cnt++;
			continue;
		}
		if(fx==0)
			ix++,cnt++;
		if(fx==1)
			ix--,cnt++;
	}
	return 0;
}