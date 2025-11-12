#include<bits/stdc++.h>
using namespace std;
int a[5010];
long long cnt=0;
void judge(int l,int r,int best,int ans,int start)
{
    if(best==r)
    {
        if(ans>a[l]*2)
        {
            cnt++;
        }
        return ;
    }
    for(int i=start; i<l; i++)
    {
        judge(l,r,best+1,ans+a[i],i+1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    long long ret=0;
    for(int i=3; i<=n; i++)
    {
        for(int j=2; j<=i-1; j++)
        {
            cnt=0;
            judge(i,j,0,0,1);
            ret+=cnt;
            ret%=998244353;
        }
    }
    printf("%d",ret);
    return 0;
}
