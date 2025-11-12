#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
    freopen("polygon","r",stdin);
    freopen("polygon","w",stdout);
    int n,b,maxx=0,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cnt+=a[i];
        maxx=max(maxx,a[i]);
    }
    if(2*maxx<cnt)
        printf("1");
    else
        printf("0");
    return;
}
