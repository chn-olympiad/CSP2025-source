#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int a,b,c[1000],px=1,l,h;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=b*a;i++ ){
        cin>>c[i];
      if(c[i]>c[1])px++;
    }
     if(px%a==0)l=px/a;
       else l=px/a+1;
       if(l%2==0)h=a-px/2+1;
       else if(l<2)h=px/2+1;
         else h=px/a-1;
         if(h<0)h*=-1;
         cout<<l<<' '<<h;
    return 0;
    }


