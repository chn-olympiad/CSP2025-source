#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int u=3;
    int p=0;
    int h=0;
    int t=0;
    cin>>n;
    vector <int> a(n,0);
    vector <int> b(n,0);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];


    }

     for(int z=0; z<n; z++)
     {
         for(int j=0; j<n-u+1; j++)
         {

             for(int v=0; v<u; v++)
             {
                 p+=a[j+v];

             }


             for(int i=j; i<j+u; i++)
             {
                 if(t<a[i])
                 {
                     t=a[i];
                     //cout<<t;
                 }
             }

             if(p>t*2)
             {
                 h++;
             }


             p=0;
             t=0;



         }
         u++;
     }

    cout<<h;
    return 0;



}
