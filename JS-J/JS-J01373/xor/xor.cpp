#include<bits/stdc++.h>
using namespace std;
struct qj
{
    int left;
    int right;
};
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n+1];
    int pre[n+1];
    pre[0]=0;
    int one=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]^a[i];
        one+=(a[i]==1?1:0);
    }
    if(one==n&&k==0)
    {
        cout<<n/2<<endl;
        return 0;
    }
    int cnt=0;
    qj lr[n*(n+1)/2];
    for(int l=1;l<=n;l++)
    {
        for(int r=l;r<=n;r++)
        {
            if((pre[r]^pre[l-1])==k)
            {
                lr[cnt].left=l;
                lr[cnt].right=r;
                cnt++;
            }
        }
    }
    sort(lr,lr+cnt,[](qj a,qj b){return a.left<b.left;});
    int ans=cnt;
    for(int i=1;i<cnt;i+=2)
    {
        if(!(lr[i-1].right<lr[i].left)) ans--;
    }
    cout<<ans<<endl;
    return 0;
}
