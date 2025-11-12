#include<bits/stdc++.h>
using namespace std;
int a[1100000],b[1100000];
int t[4400000];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int top,i,n,k;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    b[0]=0;
    for(i=1;i<=n;i++)b[i]=(b[i-1]^a[i]);
    top=1;
    t[k]=1;
    for(i=1;i<=n;i++)
    {
        if(t[b[i]]==top)top++;
        t[b[i]^k]=top;
    }
    printf("%d",top-1);
    return 0;
}
