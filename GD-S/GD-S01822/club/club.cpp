#include<bits/stdc++.h>
using namespace std;
long long i,j,k,t,n,a1,a2,a3,cnt,ans;
struct oier{
    long long d1,d2,d3;
}a[100005];
bool cmp23(oier x,oier y)
{
    return x.d1>y.d1;
}
int main(){
    ///*
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    //*/
    scanf("%lld",&t);
    while(t--)
    {
        a2=a3=ans=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld%lld%lld",&a[i].d1,&a[i].d2,&a[i].d3);
            a2+=a[i].d2;
            a3+=a[i].d3;
        }
        if(a2==0&&a3==0)//#12 5p
        {
            sort(a,a+n,cmp23);
            for(i=0;i<n/2;i++) ans+=a[i].d1;
            printf("%lld\n",ans);
            continue;
        }
        a1=a2=a3=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<3;j++)
            {
                ;
            }
        }
    }
    return 0;
}
/*
NOI Linux 123456
  ^ ^
 (OvO)
*/
