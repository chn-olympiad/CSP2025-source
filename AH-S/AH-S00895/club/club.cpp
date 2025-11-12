#include<bits/stdc++.h>
using namespace std;
int n,ans,a[100001][4],b[100001],cnt[4];
void f(int i,int sum){
    if(i==n+1)
    {
        ans=max(ans,sum);
        return;
    }
    for(int j=1;j<=3;j++)
    {
        if(cnt[j]<n/2)
        {
            cnt[j]++;
            f(i+1,sum+a[i][j]);
            cnt[j]--;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        cnt[1]=cnt[2]=cnt[3]=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        ans=0;
        if(n==2)
        {
            for(int i=1;i<=3;i++)
            {
                for(int j=1;j<=3;j++)
                {
                    if(i==j)continue;
                    ans=max(ans,a[1][i]+a[2][j]);
                }
            }
            printf("%d\n",ans);
            continue;
        }
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            if(a[i][2]!=0||a[i][3]!=0)
            {
                flag=false;
                break;
            }
        }
        if(flag==true)
        {
            for(int i=1;i<=n;i++)b[i]=a[i][1];
            sort(b+1,b+n+1);
            for(int i=n;i>n/2;i--)ans+=b[i];
            printf("%d\n",ans);
            continue;
        }
        f(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
