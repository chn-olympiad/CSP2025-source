#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",std.in);
     freopen("polygon.out","w",std.out);
     int m,n,ans,big,s,a[100];
     cin>>n;
     for(int i=1;i<=n;i++)
     {
         cin>>a[i];
         ans=ans+a[i];
           for(int j=0;j<=i;j++)
                {
                    if(a[i]>a[i-1])
                        big=a[i];
                    else big=a[i-1];
                }
         if(i>=3){

            if(ans>2*big)s+=1;
         }
     }
     cout<<s<<endl;
return 0;
}
