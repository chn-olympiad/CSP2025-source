#include<bits/stdc++.h>
using namespace std;
long long a,b,as[501],bs[501],out,d,zero,zero2,fac=1,pre[501];
const int m=998244353;
string c;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c;
	for(int i=1;i<=a;i++)
	{
		cin>>as[i];
		bs[i]=i;
		pre[i]=pre[i-1];
		if(c[i-1]!='1')zero2++,pre[i]=pre[i-1]+1;
		if(!as[i])zero++;
		fac*=i;fac%=m;
	}
	if(zero+b>a||zero2+b>a)
	{
		cout<<0;
		return 0;
	}
	if(b==1)
	{
		sort(as+1,as+a+1);out=1;
		for(int i=a;i;i--)
		{
			if(pre[as[i]]+i-as[i]<0)
			{
				out=0;
				break;
			}
			out*=pre[as[i]]+i-as[i];
			out%=m;
		}
		cout<<(fac+m-out)%m;
		return 0;
	}
	if(a==b)
	{
		if(zero||zero2)cout<<0;
		else cout<<fac;
	}
	do
	{
		d=0;
		for(int i=1,j=0;i<=a;i++)
		{
			if(c[i-1]=='1'&&j<as[bs[i]])d++;
			else j++;
		}
		if(d>=b)out++;
	}while(next_permutation(bs+1,bs+a+1)); 
	cout<<out;
	return 0;
}
