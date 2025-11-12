#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
long long n,m,i,j,k,a[N][3],ans,as,e[3];
struct st
{
    long long z,b;
}b[N];
bool f(st a,st b)
{
    return a.z>b.z;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long T;
    cin>>T;
    for(;T>0;T--)
    {
        e[0]=e[1]=e[2]=0;
        ans=0;
        cin>>n;
        for(i=0;i<n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
        for(i=0;i<n;i++)
        {
            ans+=max(a[i][0],max(a[i][1],a[i][2]));
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) e[0]++;
            else if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][0]) e[1]++;
            else  e[2]++;
        }
        if(max(e[0],max(e[1],e[2]))<=n/2)
        {
            cout<<ans<<"\n";
            continue;
        }
        if(e[0]>=e[1]&&e[0]>=e[2]) i=0;
          else  if(e[1]>=e[2]&&e[1]>=e[0]) i=1;
            else  i=2;
        as=ans=0;
        for(j=0;j<n;j++)
        {
            b[j].z=a[j][i]-max(a[j][(i+1)%3],a[j][(i+2)%3]);
            b[j].b=max(a[j][(i+1)%3],a[j][(i+2)%3]);
        }
        sort(b,b+n,f);
        for(j=0;j<n;j++) as+=b[j].b;
        for(j=0;j<n/2;j++) as+=b[j].z;
        ans=max(ans,as);
        cout<<ans<<"\n";
    } 
    return 0;
}
