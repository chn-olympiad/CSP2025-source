#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int w=1;w<=t;w++)
    {
        int n,a[100005],b[100005],c[100005],s=0,u=0,v=0,sm=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int x,y,z,ss=0;
            cin>>x>>y>>z;
            ss=max(ss,x);
            ss=max(ss,y);
            ss=max(ss,z);
            sm+=ss;
            if(ss==x)
            {
                s++;
                a[s]=min(x-y,x-z);
            }
            else if(ss==y)
            {
                u++;
                b[u]=min(y-x,y-z);
            }
            else
            {
                v++;
                c[v]=min(z-y,z-x);
            }

        }
        if(s>n/2)
        {
            sort(a+1,a+s+1);
            for(int i=1;i<=s-n/2;i++)
            {
                sm-=a[i];
            }
        }
        if(u>n/2)
        {
            sort(b+1,b+u+1);
            for(int i=1;i<=u-n/2;i++)
            {
                sm-=b[i];
            }
        }
        if(v>n/2)
        {
            sort(c+1,c+v+1);
            for(int i=1;i<=v-n/2;i++)
            {
                sm-=c[i];
            }
        }
        cout<<sm<<endl;
    }
    return 0;
}
