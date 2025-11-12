#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353,N=510;
int a[N],b[N],q[N];
signed main(){
    freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
    int n,m;cin>>n>>m;
    string s;cin>>s;s=" "+s;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=10){
        for(int i=1;i<=n;i++) q[i]=i;
        int ans=0;
        do{
            for(int i=1;i<=n;i++) b[i]=a[q[i]];
            int re=0;
            for(int i=1;i<=n;i++){
                if(re>=b[i]||s[i]=='0') re++;
            }
            if(n-re>=m) ans++;
        }while(next_permutation(q+1,q+n+1));
        cout<<ans<<'\n';
        return 0;
    }
    int num=0,cnt=0;
    for(int i=1;i<s.size();i++) if(s[i]=='1') num++;
    for(int i=1;i<=n;i++) if(a[i]!=0) cnt++;
    if(num<m||cnt<m){
        cout<<0<<'\n';
        return 0;
    }
    int ans=1;
    for(int i=2;i<=n;i++) ans=(ans*i)%p;
    cout<<ans<<'\n';
}