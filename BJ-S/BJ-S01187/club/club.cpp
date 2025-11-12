#include<bits/stdc++.h>
using namespace std;
int t,n,a1,a2,a3,x,y,z,b1,b2,b3;
int main()
{
    freopen("club.in","r",stdin);
     freopen("club.out","w",stdout);
     cin>>t;
     while(t--)
     {
		 cin>>n;
		 b1=0,b2=0,b3=0,a1=0,a3=0,a2=0;
		 for(int i=1;i<=n;i++)
		 {
			 cin>>x>>y>>z;
			 if(x==max(x,max(y,z))&&(n/2)>=b1+1)
			 {
				 a1+=x;
				 b1++;
			 }
			  if(z==max(x,max(y,z))&&(n/2)>=b3+1)
			 {
				 a3+=z;
				 b3++;
			 }
			  if(y==max(x,max(y,z))&&(n/2)>=b2+1)
			 {
				 a2+=y;
				 b2++;
			 }
			 
		 }
		 cout<<a1+a2+a3<<endl;
	 }
    return 0;
}
