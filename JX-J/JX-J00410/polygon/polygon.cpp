#include<bits/stdc++.h>
#define int long long
#define F(i,n,m) for(int i=n;i<=m;i++)
#define f(i,n,m) for(int i=n;i<m;i++)
#define FF(i,n,m) for(int i=n;i>=m;i--)
#define ff(i,n,m) for(int i=n,i>=m;i--)
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;
const int N=5e3+10;
int n,k,ans,t=1,a[N],s[N];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    F(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    if(n==3){
        if(a[1]+a[2]+a[3]>2*a[3]) cout<<1;
        else cout<<0;
    }
    return 0;
}