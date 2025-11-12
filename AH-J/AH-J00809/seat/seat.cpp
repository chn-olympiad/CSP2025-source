#include<bits/stdc++.h>
using namespace std;
long long n,m,temp,a[105]={0},id,cnt;
bool cmp(long long x,long long y)
{
    return x>y;
}
int main(void){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n*m;i++)
        scanf("%lld",&a[i]);
    temp=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
            for(int j=1;j<=n;j++)
            {
                cnt++;
                if(a[cnt]==temp)
                    printf("%lld %lld",i,j);
            }
        else
            for(int j=n;j>=1;j--)
            {
                cnt++;
                if(a[cnt]==temp)
                    printf("%lld %lld",i,j);
            }
    }
    return 0;
}
