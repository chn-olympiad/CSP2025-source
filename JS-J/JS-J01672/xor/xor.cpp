#include <bits/stdc++.h>
using namespace std;
int a[50005];
//int s[50005];
struct tdot
{
    int l, r;
}b[5000005];
bool cmp(tdot x, tdot y)
{
    if(x.l!=y.l) return x.l<y.l;
    else return x.r<y.r;
}
int check(int l, int r)
{
    int cnt=a[l];
    for(int i=l+1;i<=r;i++)
    {
        cnt=(cnt^a[i]);
    }
    return cnt;
}
bool check2(int j, int p)
{
    return b[j].r<b[p].l;
}

int main()
{
    //int x, y;
   // cin>>x>>y;
    //cout<<(x^y)<<endl;
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n, k;
    cin>>n>>k;
    cin>>a[1];
//    s[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
   //     s[i]=(a[i]^s[i-1]);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(check(i, j)==k)
            {
              //  cout<<s[j]<<' '<<s[i]<<endl;
                b[++cnt].l=i;
                b[cnt].r=j;
            }
        }
    }
    sort(b+1, b+cnt+1, cmp);
    int maxn=0;
    for(int i=1;i<=cnt;i++)
    {
      /*  cout<<b[i].l<<' '<<b[i].r<<endl;*/
        int j=i, p=i+1;
        int num=1;
        while(j<=cnt&&p<=cnt)
        {
            //cout<<b[j].l<<' '<<b[j].r<<endl;
            if(check2(j, p))
            {
              //  cout<<b[j].r<<' '<<b[p].l<<endl;//<<' '<<b[p].l<<' '<<b[p].r<<endl;
               // if(b[p].l==0) cout<<p<<endl;
                num++;
              //  cout<<j<<' '<<p<<' '<<num<<endl;
                j=p;
            }
            p++;
        }
        //cout<<endl;
        maxn=max(maxn, num);
    }
    cout<<maxn<<endl;
    return 0;
}
