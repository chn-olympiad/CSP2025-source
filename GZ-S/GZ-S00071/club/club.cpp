//GZ-S00071 贵阳市第三实验中学 包雨桐 
#include <bits/stdc++.h>
using namespace std;
struct club{
	int n;
	int a[10005][8];
};
long long int x;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>x;
	club y;
	int b[105],c=0,d[105],sum=0;
	for(int i=0;i<x;i++)
	{
	   sum=0;
	   cin>>y.n;
	   for(int j=0;j<y.n;j++)
	   {
	   	int max=0,min=y.a[j][1];
	     	for(int k=0;k<3;k++)
	        {
	   	        cin>>y.a[j][k];
	   	        if(y.a[j][k]>max)
	   	        {	c++;
	   	        	b[c]=y.a[j][k];
	   	        	max=y.a[j][k];
				
				}
				else if(y.a[j][k]<min)
				{
					min=y.a[j][k];
				}
				else
				{	c++;
					b[c]=y.a[j][k];
				    
				 } 
	        }
       }
       sort(b+1,b+x);
       for(int g=c;g>c-y.n-1;g--)
       {
       	sum=sum+b[g]; 
	   }
	   for(int g=c;g>0;g--)
       {
       	b[g]=0; 
	   }
	  	d[i]=sum;
	}
	for(int i=0;i<x;i++) cout<<d[i]<<" ";
	return 0;
} 
