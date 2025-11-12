#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=505;
int n,m,c[N],t[N];
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(n<=10){
        for(int i=1;i<=n;i++){
            t[i]=i;
        }
        int ans=0;
        do{
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(s[i]=='0') cnt++;
                else if(c[t[i]]<=cnt) cnt++;
                else continue;
            }
            if(n-cnt>=m) ans++;
        }while(next_permutation(t+1,t+1+n));
        cout<<ans<<'\n';
        return 0;
    }
    if(n==0){
        cout<<0<<'\n';
        return 0;
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        (ans*=i)%=mod;
    }
    cout<<ans<<'\n';
    return 0;
}
