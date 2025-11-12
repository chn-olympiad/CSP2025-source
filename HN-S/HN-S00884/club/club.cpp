#include<bits/stdc++.h>
using namespace std;
int n,t,x[100001],y[100001],z[100001],a,b,c,ans,zw,xw,yw;
bool w[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		
		if(n==2)
		{
			for(int j=1;j<=2;j++)
			{
				cin>>x[j]>>y[j]>>z[j];
			}
			
			cout<<max(x[1]+y[2],max(x[1]+z[2],max(y[1]+x[2],max(y[1]+z[2],max(z[1]+x[2],z[1]+y[2])))));	
		}
			
		else
		{
		for(int j=1;j<=n;j++)
		{
			cin>>x[j]>>y[j]>>z[j];
			if(x[j]!=0)
				xw++;
			if(y[j]!=0)
				yw++;
			if(z[j]!=0)
				zw++;	
		}
		
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		sort(z+1,z+n+1);
		
		if(yw==0&&zw==0)
		{
			cout<<x[n]+x[n-1];
			return 0;
		}
		
		for(int j=0;j<=n/2;j++)
		{
			a+=x[n-j];
			b+=y[n-j];
			c+=z[n-j];
		}
		
		cout<<a+b+c;
		a=0;b=0;c=0;
		}
		
		
	}	
return 0;
}

