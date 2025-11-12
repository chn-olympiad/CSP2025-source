#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rof(i,a,b) for(int i=a;i>=b;i--)
#define fs first
#define sc second
using namespace std;
const int N=1e5+5;
int n,m,a[N],p[N],c[N];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin>>n>>m;
    int ans=0;
    For(i,1,n)a[i]=i;
    For(i,1,n)
    {
        char c;cin>>c;
        p[i]=c-'0';
    }
    For(i,1,n)cin>>c[i];
    do
    {
        int now=0,can=0;
        For(i,1,n)
        {
            if(can>=m)break;
            if(p[i]==0){now++;continue;}
            if(now>=c[a[i]]){now++;continue;}
            can++;
        }
        // For(i,1,n)cout<<a[i]<<' ';
        // cout<<can<<endl;
        if(can>=m)ans++;
    }while(next_permutation(a+1,a+n+1));
    cout<<ans;
    return 0;
}