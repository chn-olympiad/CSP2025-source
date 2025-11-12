#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,t,y,u,o,e=0;
long long q=0;
long long  a[1000];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
cin>>n>>m;
q=n*m;
	for(int i=1;i<=q;i++)
	{
		cin>>a[i];
	}
	if((n==1)&&(m==1))
	{
		cout<<1<<" "<<1;
	}else{
//	if((n==1)&&(m<=10))
//	{
for(int i=1;i<=n;i++)
{
	if(a[i]>a[i+1])
	{
//		y=a[i];
//		a[i]=a[i+1];
//		a[i+1]=y;
		e++;
	}
		
}
	t=e+1;
	c=t/n;
	r=t%m;
	if(r==0)
	{
		cout<<c<<" "<<m;
	}else{
		cout<<c<<" "<<r;
	}
	
//			for(int i=1;i<=q;i++)
//	{
////			cout<<a[i]<<" ";
//			r=a[i]-a[i-1];
//			c=a[i]/n;
//		cout<<1<<" "<<r;
//}
//			
////	}
}
fclose(stdin);
fclose(stdout);
	return 0;
} 
