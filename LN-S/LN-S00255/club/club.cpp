#include<bits/stdc++.h>
using namespace std;
struct abc
{
    int my1;
    int my2;
    int my3;
};
abc a[100001];
int s=0,n;
int bcd(int x,int y,int bm1,int bm2,int bm3)
{
    if(bm1>n/2 || bm2>n/2 || bm3>n/2)
    {
        return 0;
    }
    if(x>n)
    {
        s=max(y,s);
        return 0;
    }
    bcd(x+1,y+a[x].my1,bm1+1,bm2,bm3);
    bcd(x+1,y+a[x].my2,bm1,bm2+1,bm3);
    bcd(x+1,y+a[x].my3,bm1,bm2,bm3+1);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].my1>>a[i].my2>>a[i].my3;
        }
        bcd(1,0,0,0,0);
        cout<<s<<endl;
        s=0;
    }
    return 0;
}
