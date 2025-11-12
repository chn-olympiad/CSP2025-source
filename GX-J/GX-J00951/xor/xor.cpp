#include<bits/stdc++.h>
using namespace std;
int a[500010];
int n,m;
int judge(int p,int maxn)
{
    int cnt=0;
    int new_maxn=1e9;
    for(int i=p; i<=maxn; i++)
    {
        cnt^=a[i];
        if(cnt==m)
        {
            new_maxn=min(new_maxn,i);
            new_maxn=min(new_maxn,judge(i+1,i));
            break;
        }
    }
    return new_maxn;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    int start=1;
    int ret=0;
    while(start<=n)
    {
        start=judge(start,n);
        if(start==1e9)
        {
            break;
        }
        start++;
        ret++;
    }
    printf("%d",ret);
    return 0;
}
