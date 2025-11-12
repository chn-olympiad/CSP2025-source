#include<bits/stdc++.h>
using namespace std;
long long n,i,t,ans,x1,x2,x3,y1,y2,y3,b[5],c[5];
int main(){
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		y1=1,y2=2,y3=3;
		for(int i=1;i<=n;i++)
		{
		    cin>>x1>>x2>>x3;	
		    if(x2<x3){
		        swap(x2,x3);
		        swap(y2,y3);
			}if(x1<x2){
				swap(x1,x2);
				swap(y1,y2);
			}if(x2<x3){
		        swap(x2,x3);
		        swap(y2,y3);
		    }
		    if(c[y1]<n/2) c[y1]++,b[y1]+=x1;
			else if(c[y2]<n/2) c[y2]++,b[y2]+=x2;
			else c[y3]++,b[y3]+=x3; 
		}
		cout<<b[y1]+b[y2]+b[y3]<<endl;
		c[1]=0,c[2]=0,c[3]=0;
		b[1]=0,b[2]=0,b[3]=0;
    }
	
	return 0;
}
