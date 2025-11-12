#include<bits/stdc++.h>
using namespace std;
int t,n;
long long mx;
bool p=true,q=true;
struct str{
    int x,y,z,cha;
}a[200005];
struct str2{
    int num,sum;
}b[5];
void f(int c)
{
    if(c==n+1)
    {
        if(mx<=b[1].sum+b[2].sum+b[3].sum) mx=b[1].sum+b[2].sum+b[3].sum;
        return ;
    }
    for(int i=1;i<=3;i++)
    {
        if(b[i].num<n/2)
        {
            b[i].num++;
            if(i==1) b[i].sum+=a[c].x;
            if(i==2) b[i].sum+=a[c].y;
            if(i==3) b[i].sum+=a[c].z;
            f(c+1);
            b[i].num--;
            if(i==1) b[i].sum-=a[c].x;
            if(i==2) b[i].sum-=a[c].y;
            if(i==3) b[i].sum-=a[c].z;
        }
    }
    return ;
}
bool pd(str a1,str b1)
{
    return a1.x>b1.x;
}
bool pd2(str a1,str b1)
{
    return a1.cha>b1.cha;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        b[1].num=b[2].num=b[3].num=b[1].sum=b[2].sum=b[3].sum=0;
        mx=0;
        scanf("%d",&n);
        int x,y,z;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
            a[i].cha=a[i].x-a[i].y;
            if(a[i].y!=0||a[i].z!=0) p=false;
            if(a[i].z!=0) q=false;
        }
        if(p==true)
        {
            sort(a+1,a+n+1,pd);
            for(int i=1;i<=n/2;i++)
            {
                mx+=a[i].x;
            }
            printf("%lld\n",mx);
            continue;
        }
        if(q==true)
        {
            sort(a+1,a+n+1,pd2);
            for(int i=1;i<=n;i++)
            {
                if(i<=n/2) mx+=a[i].x;
                else mx+=a[i].y;
            }
            printf("%lld\n",mx);
            continue;
        }
        f(1);
        printf("%lld\n",mx);
    }
    return 0;
}
