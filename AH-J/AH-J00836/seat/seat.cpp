#include<bits/stdc++.h>
using namespace std;
long long a[105];
int n,m,c=1,r=0,f=1;
bool tmp(long long x,long long y)
{
	return x>y;
}
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
   cin>>n>>m;
   int v=n*m;
   for(int i=1;i<=v;i++)
	   cin>>a[i];
   int t=a[1],s;
   sort(a+1,a+1+v,tmp);
   for(int i=1;i<=v;i++){
	   if(a[i]==t)
	   {
	      s=i;
	      break;
       }
   }
   for(int i=1;i<=v;i++){
	   r+=f;
	   if((r==n+1&&f==1)||(r==0&&f==-1))
	   {
		   r-=f;
		   f*=-1;
		   c+=1;
	   }
	   if(i==s)
	   break;
   }
   	cout<<c<<' '<<r;   
   return 0;
}

