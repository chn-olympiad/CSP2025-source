#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int a,b,f=0,d=0;
    cin>>a;
    int c[9999];
    for(int i=1;i<=a;i++)
    {
        cin>>b;
        for(int j=1;i<=b;j++)
        {
            for(int q=1;q<=3;q++)
            {
               cin>>c[q];
               if(f<c[q])
               {
                    f=c[q];
                    d=d+f;
               }
            }
        }
    }
    cout<<d;
    fclose(stdin);
    fclose(stdout);
}
