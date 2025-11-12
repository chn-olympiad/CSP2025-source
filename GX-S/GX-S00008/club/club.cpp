#include<bits/stdc++.h>
using namespace std;
int t;
struct z{
    int a;
    int b;
    int c;
};
int main()
{
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin>>t;
    for(int s=0;s<t;s++)
    {
        int n,m=0;
        cin>>n;
        z x[n];
        for(int i=0;i<n;i++)
        {
            cin>>x[i].a>>x[i].b>>x[i].c;
        }
        sort(x,x+n);
        int d,e,f,g;
        for(int i=0;i<n;i++)
        {
            if(max(x[i].a,x[i].b,x[i].c)==x[i].a&&n/2>e)
            {
                d=d+x[i].a;
                e=e+1;
            }
            x[i].a=0;
            if(max(x[i].a,x[i].b,x[i].c)==x[i].b&&n/2>f)
            {
                d=d+x[i].b;
                f=f+1;
            }
            x[i].b=0;
            if(max(x[i].a,x[i].b,x[i].c)==x[i].c&&n/2>g)
            {
                d=d+x[i].c;
                g=g+1;
            }
        }
        cout<<d<<endl;
    }
    }
