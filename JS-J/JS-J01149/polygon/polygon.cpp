#include<bits/stdc++.h>
using namespace std;



int n,x,y;
long long n2[5005];
long long ans;
const long long mod=998244353;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    vector<int> a(n+1);


    n2[0]=1;
    for(int i=1;i<=n;++i)
    {
        n2[i]=2*n2[i-1]%mod;
    }


    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());

    for(int i=3;i<=n;++i)
    {
        int it1=upper_bound(a.begin(),a.end(),ceil(a[i]/2.0))-a.begin();
        int it2=lower_bound(a.begin(),a.end(),floor(a[i]/2.0))-a.begin();
        if(it2>=it1 || it1>=i)
        {
            continue;
        }
        cout<<i<<" "<<it1<<" "<<it2<<endl;
        ans+=(i-it1-1)*n2[it2-1]%mod;
        for(it2;it2<i-1;it2++)
        {
            ans+=n2[it2-1]%mod;
        }
        cout<<ans<<endl;


    }
    cout<<ans+1;
    return 0;
}
