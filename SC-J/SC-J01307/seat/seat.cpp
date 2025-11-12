#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
int n,m,pos,pts;
int a[N];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m*n;i++)
	{
		scanf("%lld",&a[i]);
	}
	pts=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==pts)
		{
			pos=i;
			break;
		}
	}
	int p=0;
	while(pos>n)
	{
		pos-=n;
		p++;
	}
	cout<<p+1<<" ";
	if(p%2==1)
	{
		cout<<n-pos+1;
	}
	else
	{
		cout<<pos;
	}
	return 0;
}
/*
//freopen
//feropen
//T2 is so hard 
//Thanks to Mrs.He so that I can have a Yizhao(My zhun Kao zheng is black and white) 
//Luogu search fengzhaoyu
//Luogu search XXh0919
//Luogu search xiangxiyu
//they are my friends(Dou bu shi wo)
//I wish they can RP++
//And me
*/