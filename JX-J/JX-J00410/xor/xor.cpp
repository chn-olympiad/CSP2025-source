#include<bits/stdc++.h>
#define int long long
#define F(i,n,m) for(int i=n;i<=m;i++)
#define f(i,n,m) for(int i=n;i<m;i++)
#define FF(i,n,m) for(int i=n;i>=m;i--)
#define ff(i,n,m) for(int i=n,i>=m;i--)
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;
const int N=5e5+10;
int n,k,ans,t=1,a[N],s[N];
bool fl=0;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    F(i,1,n){
        cin>>a[i];
        if(a[i]>0) fl=1;
        if(a[i]==k) ans++;
    }
    if(!fl) cout<<n/2;
    else{
        f(i,1,n){
            int cnt=a[i]^a[i+1];
            F(j,i+2,n){
                cnt^=a[j];
                if(a[j]==k){
                    i=j+1;
                    j=i+2;
                    cnt=a[i]^a[i+1];
                    continue;
                }
                if(cnt==k){
                    ans++;
                    i=j+1;
                    j=i+2;
                    cnt=a[i]^a[i+1];
                }
            }
        }
    }
    cout<<ans;
    return 0;
}