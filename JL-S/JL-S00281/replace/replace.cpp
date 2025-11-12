#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int base = 13331,N = 300010;
int n,q;
int len[N];
int h1[N],h2[N];
int get_hash(string s){
    int sz = s.size();
    int res = 0,tmp = 1;
    for(int i = 0;i<sz;i++){
        res+=((int)s[i])*tmp;
        tmp*=base;
    }
    return res;
}
string s1,s2;
int f[N];
int sum1[N],sum2[N];
int l;
int ans;
void solve(){
    ans = 0;
    cin>>s1>>s2;
    if(s1.size()!=s2.size()){
        cout<<"0\n";
        return;
    }
    l = s1.size();
    for(int i = 1;i<=l;i++){
        sum1[i] = sum1[i-1]+(((int)s1[i-1])*f[i]);
        sum2[i] = sum2[i-1]+(((int)s2[i-1])*f[i]);
    }
    for(int k = 1;k<=n;k++){
        for(int i = 1,j = i+len[k]-1;j<=l;i++,j++){
            if(sum1[j]-sum1[i-1]!=h1[k]*f[i])continue;
            if(sum1[l]-sum1[j]+sum1[i-1]+h2[k]*f[i]==sum2[l]){
                ans++;
                break;
            }
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    f[1] = 1;
    for(int i = 2;i<=(N-10);i++){
        f[i] = f[i-1]*base;
    }
    for(int i = 1;i<=n;i++){
        string ss1,ss2;
        cin>>ss1>>ss2;
        len[i] = ss1.size();
        h1[i] = get_hash(ss1);
        h2[i] = get_hash(ss2);
    }
    for(int i = 1;i<=q;i++){
        solve();
    }
    return 0;
}
