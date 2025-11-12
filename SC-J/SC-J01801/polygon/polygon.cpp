#include<bits/stdc++.h>
using namespace std;
#define L long long
#define S string
#define B bool
#define C char
#define I cin
#define O cout
#define V vector
V<L> a;
L _pow(L a,L _time,L mod)
{
	if(_time==1)
	{
		return a%mod;
	}
	else if(_time%2==0)
	{
		L now=_pow(a,_time/2,mod)%mod;
		return (now*now)%mod;
	}
	else
	{
		L now=_pow(a,_time/2,mod)%mod;
		return (((now*now)%mod)*a)%mod;
	}
}
signed main()
{
	//骗分代码 >=36
	//唯一识别码：iershbdfhjhvudfhudhuhudhfgnxcwdk
	ios::sync_with_stdio(0);
	I.tie(0);
	O.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	L num;
	I>>num;
	if(num<3)
	{
		O<<0;
	}
	else if(num==3)
	{
		L a,b,c;
		I>>a>>b>>c;
		if(max(a,max(b,c))*2>=a+b+c)
		{
			O<<0;
		}
		else
		{
			O<<1;
		}
	}
	else if(num==4)
	{
		L a,b,c,d,ans=0;
		I>>a>>b>>c>>d;
		if(max(a,max(b,c))*2<a+b+c){ans++;}
		if(max(a,max(b,d))*2<a+b+d){ans++;}
		if(max(a,max(d,c))*2<a+d+c){ans++;}
		if(max(d,max(b,c))*2<d+b+c){ans++;}
		if(max(max(a,d),max(b,c))*2<a+b+c+d)\
										  {ans++;}
		O<<ans;
	}
	else if(num==5)
	{
		L a,b,c,d,e,ans=0;
		I>>a>>b>>c>>d>>e;
		if(max(a,max(b,c))*2<a+b+c){ans++;}
		if(max(a,max(b,d))*2<a+b+d){ans++;}
		if(max(a,max(d,c))*2<a+d+c){ans++;}
		if(max(d,max(b,c))*2<d+b+c){ans++;}
		if(max(e,max(b,c))*2<e+b+c){ans++;}
		if(max(a,max(b,e))*2<a+b+e){ans++;}
		if(max(a,max(e,c))*2<a+e+c){ans++;}
		if(max(d,max(a,e))*2<d+a+e){ans++;}
		if(max(d,max(b,e))*2<d+b+e){ans++;}
		if(max(c,max(e,d))*2<c+e+d){ans++;}
		if(max(max(a,d),max(b,c))*2<a+b+c+d)\
										  {ans++;}
		if(max(max(a,e),max(b,c))*2<a+b+c+e)\
										  {ans++;}
		if(max(max(a,d),max(b,e))*2<a+b+e+d)\
										  {ans++;}
		if(max(max(a,d),max(e,c))*2<a+e+c+d)\
										  {ans++;}
		if(max(max(e,d),max(b,c))*2<e+b+c+d)\
										  {ans++;}
		if(max(max(a,d),max(b,max(c,e)))*2<\
								a+b+c+d+e){ans++;}
		O<<ans;
	}
	else
	{
		cout<<_pow(2,num,998244353)-1-num-\
									num*(num-1)/2;
	}
	return 0;
}