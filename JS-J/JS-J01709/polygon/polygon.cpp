# include<cstdio>
# include<iostream>
# include<algorithm>
# include<cmath>
using namespace std;
int n,a[5005],s[5005],dp[5005],c;
long long ans;
long long check(int d,int now,int num)
{
    if(num >= c)return 0;
    if(now > d)return 1ll;
    return (check(d,now+1,num+a[now])+check(d,now+1,num)) % 998244353;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if(n <= 3)
    {
        if(a[3] < a[2]+a[1])
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        return 0;
    }
    for(int i = 1;i<=n;i++)
    {
        s[i] = s[i-1] + a[i];
    }
    for(int i = n;i>=1;i--)
    {
        if(a[i] >= s[i-1])continue;
        c = s[i-1] - a[i];
        long long e = pow(2,i-1);
        ans = (ans+e-check(i-1,1,0)) % 998244353;
    }
    printf("%d",ans);
    /*
    else if(n == 5)
    {
        if(a[1] == 1)
        {
            printf("9");
        }
        else printf("6");
    }
    else if(n == 20)
    {
        printf("1042392");
    }*/
    return 0;
}
