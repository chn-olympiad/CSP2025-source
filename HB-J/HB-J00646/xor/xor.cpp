#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int n,k,cnt,flag[500005];
int anweiyihuo(int x,int y)
{
    char xx[25],yy[25],zz[25];
    int xxx=x,yyy=y,curx=0,cury=0;
    while(xxx>0)
    {
        xx[++curx]=xxx%2+'0';
        xxx/=2;
    }
    while(yyy>0)
    {
        yy[++cury]=yyy%2+'0';
        yyy/=2;
    }
    int l=min(curx,cury),ll=max(curx,cury);
    for(int i=1;i<=l;i++)
    {
        if(yy[i]!=xx[i])
            zz[i]='1';
        else
            zz[i]='0';
    }
    if(l!=ll)
    {
        if(curx>cury)
            for(int i=l+1;i<=ll;i++)
            {
                if(xx[i]=='1')
                    zz[i]='1';
                else
                    zz[i]='0';
            }
        else
            for(int i=l+1;i<=ll;i++)
            {
                if(yy[i]=='1')
                    zz[i]='1';
                else
                    zz[i]='0';
            }
    }
    long long zzzz=0,lass=1;
    for(int i=1;i<=ll;i++)
    {
        zzzz+=(zz[i]-'0')*lass;
        lass*=2;
    }
    return zzzz;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","W",stdout);
    int n,k;
    cin >> n >> k;
    int cnt0=0,cnt1=0;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
            cnt0++;
        if(a[i]==1)
            cnt1++;
    }
    if(cnt0+cnt1==n)
    {
        if(k==0)
            cout << cnt0;
        else
            cout << cnt1;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {

        if(a[i]==k)
        {
            cnt++;
            flag[i]++;
            continue;
        }
        long long last=a[i];
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]!=a[i])
            {
                int o=anweiyihuo(last,a[j]);
                if(o==k)
                {
                    for(int k=i;k<=j;k++)
                        flag[k]++;
                    cnt++;
                    break;
                }
                else
                    last=o;
            }
        }
    }
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==0)
            if(maxn!=0)
                cnt=cnt-maxn+1;
        if(flag[i]!=0)
            maxn=max(maxn,flag[i]);
    }
    if(maxn!=0)
        cnt=cnt-maxn+1;
    cout << cnt;
    return 0;
}
