#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,ti;
};
int n,k,a[500005],cnt=0,ans=0;
node b[50000005];
bool cmp(node a,node b)
{
    if(a.x==b.x)
    {
        return a.ti<b.ti;
    }
    return a.x<b.x;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=1;j<=i;j++)
        {
            int rec=a[j];
            for(int k=j+1;k<=i;k++)
            {
                rec^=a[k];
            }
            if(rec==k)
            {
                cnt++;
                b[cnt].x=j;
                b[cnt].y=i;
                b[cnt].ti=b[cnt].y-b[cnt].x;
            }
        }
    }
    sort(b+1,b+1+cnt,cmp);
    int ne=0;
    for(int i=1;i<=cnt;i++)
    {
        if(b[i].x>ne)
        {
            ne=b[i].y;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
