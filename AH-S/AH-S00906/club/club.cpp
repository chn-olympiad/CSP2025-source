#include<bits/stdc++.h>
using namespace std;
struct cl
{
    int x[3],mc,ic,lc;
};
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,x;
    cin>>t;
    for(int p=0;p<t;p++)
    {
        cin>>x;
        long long ans=0;
        cl a[x+1];
        int maxn=x/2,n[4]={0,0,0,0},temp;
        for(int i=0;i<x;i++)
        {
            cin>>a[i].x[0]>>a[i].x[1]>>a[i].x[2];
            if(a[i].x[0]>a[i].x[1]&&a[i].x[0]>a[i].x[2])
            {
                a[i].mc=0;
            }
            else if(a[i].x[1]>a[i].x[0]&&a[i].x[1]>a[i].x[2])
            {
                a[i].mc=1;
            }
            else
            {
                a[i].mc=2;
            }
            if(a[i].x[0]<a[i].x[1]&&a[i].x[0]<a[i].x[2])
            {
                a[i].lc=0;
            }
            else if(a[i].x[1]<a[i].x[0]&&a[i].x[1]<a[i].x[2])
            {
                a[i].lc=1;
            }
            else
            {
               a[i].lc=2;
            }
            a[i].ic=3-a[i].mc-a[i].lc;
        }
        for(int i=0;i<x;i++)
        {
            if(n[a[i].mc]+1<=maxn)
            {
                ans+=a[i].x[a[i].mc];
                n[a[i].mc]+=1;
            }
            else if(n[a[i].ic]+1<=maxn)
            {
                ans+=a[i].x[a[i].ic];
                n[a[i].ic]+=1;
            }
            else
            {
                ans+=a[i].x[a[i].lc];
                n[a[i].lc]+=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
