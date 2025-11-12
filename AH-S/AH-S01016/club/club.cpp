#include<bits/stdc++.h>//AFOed
using namespace std;
typedef long long ll;
int t,n,m,a[100111][4],b[4][100111],num[4];
int k(int q,int w,int e)
{
    return max(q,max(w,e));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        memset(b,0,sizeof(b));
        memset(num,0,sizeof(num));
        ll sum=0;
        scanf("%d",&n);m=n/2;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=n;i++)
        {
            int maxn=k(a[i][1],a[i][2],a[i][3]),w,p;
            sum+=maxn;
            if(maxn==a[i][1]) num[1]++,w=max(a[i][2],a[i][3]),p=1;
            if(maxn==a[i][2]) num[2]++,w=max(a[i][1],a[i][3]),p=2;
            if(maxn==a[i][3]) num[3]++,w=max(a[i][2],a[i][1]),p=3;
            b[p][num[p]]=maxn-w;
        }
        for(int i=1;i<=3;i++)
            sort(b[i]+1,b[i]+num[i]+1);
        if(num[1]<=m&&num[2]<=m&&num[3]<=m)
        {
            printf("%lld\n",sum);
            continue;
        }
//        printf("%d %d %d\n",num[1],num[2],num[3]);
        int q;
        for(int j=1;j<=3;j++) if(num[j]>m) q=j;
        for(int i=1;i<=num[q]-m;i++)
            sum=sum-b[q][i];
        printf("%lld\n",sum);
    }
	return 0;
}
