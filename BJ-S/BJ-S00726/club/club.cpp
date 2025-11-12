#include<iostream>
using namespace std;
int a[100005][5],n,ans=0,tmp=0,w[5];
void f(int p)
{
    if(p==n+1)
    {
        if(tmp>ans)
        {
            ans=tmp;
            return;
        }
    }
    for(int i=1;i<=3;i++)
    {
        if(w[i]>0)
        {
            w[i]--;
            tmp+=a[p][i];
            f(p+1);
            tmp-=a[p][i];
            w[i]++;
        }
    }
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        tmp=ans=0;
        w[1]=w[2]=w[3]=n/2;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j][1]>>a[j][2]>>a[j][3];
        }
        f(1);
        cout<<ans<<endl;
    }
    return 0;
}
