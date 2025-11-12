#include<bits/stdc++.h>
using namespace std;
struct csp{
    long long p;
    bool r;
}a[114];
bool cmp(csp x,csp y)
{
    return x.p>y.p;
}
long long n,m,nm,i,j,x,y;
int main(){
    ///*
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    //*/
    scanf("%lld%lld",&n,&m);
    nm=n*m;
    for(i=1;i<=nm;i++)
    {
        scanf("%lld",&a[i].p);
        if(i==1) a[i].r=1;
        else a[i].r=0;
    }
    sort(a+1,a+nm+1,cmp);
    /*for(i=1;i<=nm;i++)
    {
        if(a[i].r==1)
        {
            //cout<<a[i].r<<" "<<i<<" ";
            x=i/n;
            if(i%n!=0) x++;
            if(i%2==1)
            {
                if(i%n==0) y=n;
                else y=i%n;
            }
            else y=n+1-(i%n);
            break;
        }
    }
    printf("%lld %lld",x,y);*/
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i%2==1) x=i,y=j;
            else x=i,y=n+1-j;
            if(a[i*n-n+j].r)
            {
                printf("%lld %lld",x,y);
                return 0;
            }
        }
    }
    return 0;
}
/*
*/
