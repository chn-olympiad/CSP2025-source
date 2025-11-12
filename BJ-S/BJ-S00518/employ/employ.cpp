#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

const int maxn=505,p=998244353;

int n,m;
char s[maxn];
int c[maxn],d[maxn];
int c0,s0;
ll ans=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i],s0+=(s[i]=='0');
    for(int i=1;i<=n;i++)cin>>c[i],c0+=(!c[i]);
    if(n==m){
        if(s0||c0>1)cout<<0;
        else if(c0==1){
            ll ans=1;
            for(int i=1;i<n;i++)ans=ans*i%p;
            cout<<ans;
        }
        else{
            ll ans=1;
            for(int i=1;i<=n;i++)ans=ans*i%p;
            cout<<ans;
        }
        return 0;
    }
    for(int i=1;i<=n;i++)d[i]=i;
    do{
        int g0=0;
        for(int i=1;i<=n;i++)
            if(s[i]=='0'||g0>=c[d[i]])g0++;
        if(n-g0>=m)ans++;
    }while(next_permutation(d+1,d+1+n));
    cout<<ans;
    return 0;
}
