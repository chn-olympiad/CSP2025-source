#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a,b,d,sum=0,jjf[78];
	cin>>a>>b;
	char c[a+b];
	for(int i=0;i<min(4,a+b);i++)
	{
		cin>>c[i];
	}
	cin>>d;
	for(int i=0;i<min(4,a+b);i++)
	{
		if(i%3==0)
		{
			sum-=c[i]*2;
		} 
		else{
			sum+=c[i];
		}
		sum-=jjf[i%13]%3;
	}
	sum+=d;
	cout<<abs(sum/min(8,a*b)%998244353-10);
}
