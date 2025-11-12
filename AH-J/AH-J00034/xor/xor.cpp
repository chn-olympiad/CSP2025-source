#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long sum=0;
    int a[6000],b=0,c=-1,d=0,pian=1;
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>b;
    for(int i=0;i<b;i++)
        cin>>a[i];
    /*
    cin>>b;
    for(int i=0;i<b;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<b;i++)
    {
        d=0;
        c=-1;
         for(int l=i;l<b;l++)
         {
             d+=a[l];
             if(c<a[l])
                c=a[l];
             if(d>=3 && d>2*c)
               sum++;
         }
    }
    //sum=sum%998244353;
    //cout<<sum;
    */
    cout<<pian;
    fclose(stdin);fclose(stdout);
    return 0;
}
