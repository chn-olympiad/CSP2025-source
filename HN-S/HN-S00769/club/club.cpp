#include<bits/stdc++.h>
using namespace std;
int que;
int num,a[100099],b[100999],c[100099],d,e,f,g,h,ans;
int abc(int m)
{
	if(a[m]<b[m]||a[m]<c[m])
	{
		return 1;
	} 
	if(b[m]<a[m]||b[m]<c[m])
	{
		return 2;
	} 
	if(c[m]<b[m]||c[m]<a[m])
	{
		return 3;
	} 
}
int main()
{
	freopen("club.in","r",stdin)
	freopen("club.out","w",stdout)
	cin>>que;
	for(int p=1;p<=que;p++)
	{
		
		cin>>num;
		for(int i=1;i<=num;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
			if(num==2)
		{
			int m=abc(1),n=abc(2);
			if(m==n)
			{
				
			 } else{
			 	if(m==1)
			 	{
			 		d==a[1];
				 }
				 if(m==2)
				 {
				 	d==b[1];
				 }
				 if(m==3){
				 	d==c[1];
				 }
				 if(n==1)
			 	{
			 		e==a[1];
				 }
				 if(n==2)
				 {
				 	e==b[1];
				 }
				 if(n==3){
				 	e==c[1];
				 }
				 cout<<d+e;
			 }
		}
	}
	return 0;
 } 
