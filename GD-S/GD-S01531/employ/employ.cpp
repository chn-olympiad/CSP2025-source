#include<bits/stdc++.h>
using namespace std;
struct dd
{
	long long a,b,c;
}k[100005];
bool cmp(dd x,dd y){
	return x.a>y.a;
}
bool cmp1(dd x,dd y){
	return x.b>y.b;
}
bool cmp2(dd x,dd y){
	return x.c>y.c;
}
bool amp(dd x,dd y){
	if(x.a==y.a)return x.b>y.b;
	return x.a>y.a;
}
bool bmp(dd x,dd y){
	if(x.b==y.b)return x.a>y.a;
	return x.b>y.b;
}
bool tmp(dd x,dd y){
	if(x.c==y.c)return x.a>y.a;
	return x.c>y.c;
}
long long n,m,l1,l2,l3,d,q,s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%lld",&m);
	while(m--)																																																																																																																																																																																																																																																																																																																																																																																	
	{				
		l1=0,l2=0,l3=0,s=0,d=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			cin>>k[i].a>>k[i].b>>k[i].c;
		}
		int t=n/2;//俱乐部的人数不得超过这个值 
		sort(k+1,k+n+1,cmp);//排第一个的满意值 
		for(int i=1;i<=t;i++)l1=l1+k[i].a;//将每一个俱乐部的满意值前t个求出来 
		sort(k+1,k+n+1,cmp1);
		for(int i=1;i<=t;i++)l2=l2+k[i].b;
		sort(k+1,k+n+1,cmp2);
		for(int i=1;i<=t;i++)l3=l3+k[i].c;
		for(int i=1;i<=n;i++)
		{
			if(k[i].b==0&&k[i].c==0)
			{
				l1=l1-k[t].a;
				l1=l1+k[i].a;
			}
		}
		d=max(l1,l2);
		d=max(d,l3);
		q=n-t;
		s=s+d; //先加出最大值
		if(d==l1)
		{
			sort(k+1,k+n+1,amp);
			for(int i=t+1;i<=n;i++)
			{
				if(k[i].b>k[i].c)s=s+k[i].b;
				else s=s+k[i].c;
			}
		}
		if(d==l2)
		{
			sort(k+1,k+n+1,bmp);
			for(int i=t+1;i<=n;i++)
			{
				if(k[i].a>k[i].c)s=s+k[i].a;
				else s=s+k[i].c;
			}
		}
		if(d==l3)
		{
			sort(k+1,k+n+1,tmp);
			for(int i=t+1;i<=n;i++)
			{
				if(k[i].a>k[i].b)s=s+k[i].a;
				else s=s+k[i].b;
			}
		}
		printf("%lld\n",s);
	}
	//if(n==5)cout<<n*5893*5<<endl<<n*2*12544<<endl<<30585*n+4<<endl<<(n-1)*37544<<endl<<31708*n+1;
	return 0;
}
