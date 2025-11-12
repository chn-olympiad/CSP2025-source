#include<bits/stdc++.h>
using namespace std;
#define int long long
struct abcd
{
    int from;
    int to;
} b[100000];
int n,k,a[600000],p,l,ans;
bool cmp(abcd x,abcd y)
{
    if (x.to<=y.to)
        return 1;
    if (x.to>y.to)
        return 0;
}
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for (int i=1; i<n; i++)
    {
        p=a[i];
        for (int j=i+1; j<=n; j++)
        {
            p=(p^a[j]);
        }
        if (p==k)
        {
            l++;
            b[l].from=i;
            //b[l].to=j;
        }
        if (p==k)
        {
            l++;
            b[l].from=i;
            //b[l].to=j;
        }
    }
    if (a[n]==k)
    {
        l++;
        b[l].from=n;
        b[l].to=n;
    }
    sort(b+1,b+1+l,cmp);
    int f=b[l].from,t=b[l].to,maxn=-11100;
    if (l>0)
        ans++;
    for (int i=l-1; i>=1; i--)
    {

        if (b[i].to==t)
        {
            maxn=max(maxn,b[i].from);
        }
        else
        {

            f=maxn;
            int yyy=0,zzz=0;
            for (int j=1;j<=l;j++){
                if (b[i-j].to<=f){
                    yyy=1;
                    zzz=j;
                    break;
                }
            }
            if (yyy==1){
                i-=zzz+1;
            }
            maxn=-100;
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
