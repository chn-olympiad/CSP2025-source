#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
int n, m;
char s[MAXN];
int a[MAXN];
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    cin>>s+1;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
    }
    long long ans=0;
    if(m==1)
    {
        int sum=0;
        for(int i=1; i<=n; i++)
        {
            if(s[i]=='1') break;
            sum=i;
        }
        for(int i=1; i<=n; i++)
        {
            if(a[i]>sum)ans++;
        }
        printf("%lld", ans);
    }
    else printf("0");
    return 0;

}
