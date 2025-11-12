#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
int t;
int n;
int a[N],b[N],c[N];
int num1=0;
int num2=0;
int num3=0;
int ms=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		int num=n/2;
		for(int j=i;j<=n;j++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i])
			{
				num1++;
			}
			else if(b[i]>a[i]&&b[i]>c[i])
			{
				num2++;
			}
			else if(c[i]>a[i]&&c[i]>b[i])
			{
				num3++;
			
			}
		}	
		if(num1<num)
		{
			ms+=a[i];
		}
		else if(num1>num)
		{
			if(b[i]>c[i])
			{
				ms+=b[i];
			}
			else
			{
				ms+=c[i]; 
			}
		}
		if(num2<num)
		{
			ms+=b[i];
		}
		else if(num2>num)
		{
			if(a[i]>c[i])
			{
				ms+=a[i];
			}
			else
			{
			
				ms+=c[i]; 
			}
		}
		if(num3<num)
		{
			ms+=c[i];
		}
		else if(num3>num)
		{
			if(a[i]>b[i])
			{
			ms+=a[i];
			}
			else
			{
			ms+=b[i]; 
			}
		}
		int e=ms;
		cout<<e<<endl;
	}

	return 0;	
}
