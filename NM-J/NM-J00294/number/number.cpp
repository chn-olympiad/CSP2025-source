#include<bits/stdc++.h>
using namespace std;
string s;
int a[1010];
int main()
{
     long long i,ans=0,len,k=1,t=0,j;
     freopen("number.in","r",stdin);
     freopen("number.out","w",stdout);
     cin>>s;
     len=s.length();
     for(i=0;i<len;i++)
     {
         if(s[i]>='0'&&s[i]<='9')
         {
			 a[i]=s[i]-48;
			 t++;
			 if(t==1) ans+=a[i]*1;
			 else 
			 {
				 k*=10;
				 ans+=a[i]*k;
			 }
		 }
     }
		 for(i=0;i<t;i++)
		 {
			 for(j=i+1;j<=t;j++)
             {
				 if(a[i+j]>a[i]) swap(a[i+j],a[i]);
			 }
		 }
     printf("%lld",ans);
     return 0;
}
