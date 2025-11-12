#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001],b[100001],c[100001],na,nb,nc,ans;
int main()
{
    ios::sync_with_stdio(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        na=0,nb=0,nc=0,ans=0;
        priority_queue<int> qa,qb,qc;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            if(a[i]>b[i]&&a[i]>c[i])
            {
                na++;
                qa.push(-(a[i]-max(b[i],c[i])));
                ans+=a[i];
            }
            else if(b[i]>c[i])
            {
                nb++;
                qb.push(-(b[i]-max(a[i],c[i])));
                ans+=b[i];
            }
            else
            {
                nc++;
                qc.push(-(c[i]-max(a[i],b[i])));
                ans+=c[i];
            }
            if(na>n/2)
            {
                ans+=qa.top();
                na--;
                qa.pop();
            }
            if(nb>n/2)
            {
                ans+=qb.top();
                nb--;
                qb.pop();
            }
            if(nc>n/2)
            {
                ans+=qc.top();
                nc--;
                qc.pop();
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}