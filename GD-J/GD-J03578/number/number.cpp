#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a;
	cin>>a;
	int b,c,d,e,f,g,h,i;//s-b b-c q-d w-e sw-f bw-g qw-h y-i
	if(a<10)
	{
		cout<<a;
	}
	for(int i=1;i<=a;i++)
	{
	
		if(a>=10)
		{
			b=a/10;//Ê® 
			a=a%10;//¸ö
			if(b>a)
			{
				cout<<b<<a;
			} 
			if(a>b)
				cout<<a<<b;	
		}
	}
	
	return 0;	
} 
