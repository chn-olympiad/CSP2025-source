#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long a,b,c[100000],e=0,g;
    cin>>a;
    for(long long i=1;i<=a;i++)
    {
        cin>>b;
        c[i]=b;
    }
    sort(c,c+a+1);
    if(a==3)
    {
       for(long long i=1;i<=a;i++)
       {
           e+=c[i];
       }
       if(e>2*c[a])
       {
           cout<<"1";
       }
       else cout<<"0";
    }


    if(a==4)
    {
        for(long long i=1;i<=a;i++)
       {
           e+=c[i];
       }
       for(int i=1;i<=3;i++)
       {
           if(e-c[i]>2*c[4])
           {
               g++;
           }
       }
       if(e-c[4]>2*c[3])
       {
           g++;
       }
       if(e>2*c[4])
       {
           g++;
       }
       cout<<g;
    }

    return 0;
}
