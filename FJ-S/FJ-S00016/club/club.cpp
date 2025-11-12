#include<bits/stdc++.h>
using namespace std;
long long int ans[6];
int n;
int max(int a,int b,int c)
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int m1=0;
	int max1=max(a,max(b,c));
	if(a==b||b==c||a==c)
	return max1;
	
	if(a>b&&a>c)
	{
	    m1=a;
	}
	else if(b>a&&b>c)
	{
	    m1=b;
	}		
	else
	{
	    m1=c;
	}
	int result;
	for(int j=0;j<=n/2;j++)
	{
		char m[j];
		m[j]=m1;
		result+=m[j];
	}
	cout<<result;
}
int main(){
    
	int t;
	int x1,x2,x3;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<=n;i++)
		{
			
			cin>>x1>>x2>>x3;
		}
		cout<<max(x1,x2,x3);
	}
	return 0;
}
