#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
long long t,n,a[maxn][5],sum,k;

long long f(long long i)
{
    int c[3]={},ans=0;
//    cout<<i<<' ';
    for(int j=1; j<=n; j++)
    {
//        cout<<j<<" ";
        c[i%3]++;
//        cout<<ans<<" ";
        ans+=a[j][i%3];
        i/=3;
        if(c[0]>n/2 || c[1]>n/2 || c[2]>n/2)
            return 0;
    }
//    cout<<ans<<" ";

    return ans;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;

    while(t--)
    {
        cin>>n;
        sum=0;

        for(int i=1; i<=n; i++)
            for(int j=0; j<3; j++)
                cin>>a[i][j];

        if(n<=30)
        {
            long long x=pow(3,n);
//            cout<<f(10)<<endl;
            for(long long i=1; i<x; i++)
            {
 //               cout<<f(i)<<' ';
//                    if(f(i)>sum) sum=f(i),k=i;
                sum=max(sum,f(i));
            }
            cout<<sum<<endl;
        }
        else
        {
            for(int i=1; i<=n; i++)
                sum+=max(a[i][0],max(a[i][1],a[i][2]));
            cout<<sum<<endl;
        }
    }
    return 0;
}
