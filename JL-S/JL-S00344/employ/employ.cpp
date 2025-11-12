#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,mod=998244353;
int n,m,c[N],a[N];
string s;
void bully(){
    for(int i=1;i<=n;i++) a[i]=i;
    int ans=0;
    do{
        int cnt=0,no=0;
        for(int i=1;i<=n;i++){
            int x=a[i];
            if(no>=c[x]||s[i]=='0') no++;
            else cnt++;
        }
        if(cnt>=m) ans++;  
    }while(next_permutation(a+1,a+n+1));
    cout<<ans%mod<<"\n";
    exit(0);
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;s=" "+s;
    for(int i=1;i<=n;i++) cin>>c[i];
    sort(c+1,c+n+1);
    if(n<=10) bully();
    int ans=1;
    for(int i=1;i<=n;i++) ans=ans*i%mod;
    cout<<ans<<"\n";
    return 0;
}