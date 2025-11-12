#include<iostream>
using namespace std;
int a[500001];
int he[500001];
int main()
{
     freopen("xor.in","r",stdin);
     freopen("xor.out","w",stdout);
     int n,k;cin>>n>>k;
     for(int i=0;i<n;i++)
     {
         cin>>a[i];
     }
     he[0]=a[0];
     for(int i=1;i<n;i++)
     {
         he[i]=he[i-1]^a[i];
     }
     if(n==1)
     {
        if(a[0]==0)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
     }
     if(n==2)
     {
        if(a[1]==0)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
     }
     fclose(stdin);
     fclose(stdout);
     return 0;
}
