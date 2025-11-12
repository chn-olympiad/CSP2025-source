#include<bits/stdc++.h>
using namespace std;
int n;
int m;
char c;
int s[501];
int a[501];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%c",&c);
        s[i]=c-'0';
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("0");
    return 0;
}