#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100086],b[8];
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
 cin>>t;
 for(int i=1;i<=t;i++)
  {
   cin>>n;
   for(int w=1;w<=n;w++)
    cin>>a[w];
   for(int j=1;j<=n;j++)
    cin>>b[j];
  } 
 if(ok1>ok2&&ok1>ok3)okren1++;
 if(ok1<ok2&&ok2>ok3)okren2++;
 if(ok1<ok3&&ok2<ok3)okren3++;
 sort(b,b+1+n,fuck);
 for(int i=1;i<=n;i++)
  {
   if(n/2>=ok1||n/2>=ok2||n/2>=ok3)	
    cout<<ok1+ok2+ok3<<"\n";
  }
 
 
 return 0;
}
