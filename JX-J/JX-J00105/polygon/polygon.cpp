#include<bits/stdc++.h>
using namespace std;
int main()
{   freopen("r","polygon",stdin);
    freopen("w","polygon.out",stdout);
    int n;
    cin>>n;
    if(n==1)
    {
		cout<<0;
	}
	if(n==2)
	{
		cout<<0;
	}
	if(n==3)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int s=a+b+c;
		int zd=max(c,(a,b));
		if(s>zd*2)
		{
			cout<<1;
		}
		else cout<<0;
	}
    if(n==4)
    {
		int a,b,c,d,sum=0;
		cin>>a>>b>>c>>d;
		int s1=a+b+c,s2=b+c+d,s3=a+b+c+d,s4=a+b+d,s5=a+c+d;
		int zd1=max((a,b),c),zd2=max((b,c),d),zd3=max(((a,b),c),d),zd4=max((a,b),d),zd5=max((a,c),d);
		if(s1>zd1*2) sum++;
		if(s2>zd2*2) sum++;
		if(s3>zd3*2) sum++;
		if(s4>zd4*2) sum++;
		if(s5>zd5*2) sum++;
		cout<<sum;
	}
	if(n==5)
	{
		int a,b,c,d,e,sum=0;
		cin>>a>>b>>c>>d>>e;
		int s1=a+b+c,s2=b+c+d,s3=c+d+e,s4=a+b+c+d,s5=b+c+d+e,s6=a+b+c+d+e,s7=a+c+d,s8=a+d+e,s9=b+d+e,s10=a+c+d+e,s11=a+b+d+e,s12=a+b+c+e;
		int zd1=max((a,b),c),zd2=max((b,c),d),zd4=max(((a,b),c),d),zd3=max((c,d),e),zd5=max(((b,c),d),e),zd6=max((((a,b),c),d),e),zd7=max((a,c),d),zd8=max((a,d),e),zd9=max((b,d),e),zd10=max(((a,c),d),e),zd11=max(((a,b),d),e),zd12=max(((a,b),c),e);
		if(s1>zd1*2) sum++;
		if(s2>zd2*2) sum++;
		if(s3>zd3*2) sum++;
		if(s4>zd4*2)sum++;
		if(s5>zd5*2)sum++;
		if(s6>zd6*2)sum++;
		if(s7>zd7*2)sum++;
		if(s8>zd8*2)sum++;
		if(s9>zd9*2)sum++;
		if(s10>zd10*2) sum++;
		if(s11>zd11*2) sum++;
		if(s12>zd12*2) sum++;
		cout<<sum;
	}
    return 0;
}
