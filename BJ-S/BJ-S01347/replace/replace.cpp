#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define p 37
#define N 1145
#define ll long long
ll hsh(string x){
    ll res=0;
    for(char i:x){
        res=res*p%mod;
        (res+=i-'a')%=mod;
    }
    return res;
}
int n,q;
int s[N][2],len[N];
string t1,t2;
ll ht[2222];
ll pw[2222];
int solve(){
    int ans=0,lt=t1.size();
    memset(ht,0,sizeof(ht));
    for(int i=0;i<lt;i++){
        if(i) ht[i]=ht[i-1]*p%mod;
        (ht[i]+=t1[i]-'a')%=mod;
    }
    ll ht2=hsh(t2);
    // cout<<ht[lt-1]<<' '<<ht2<<endl;
    for(int i=1;i<=n;i++){
        for(int j=0;j+len[i]<=lt;j++){
            ll tmp=ht[j+len[i]-1];
            if(j) tmp=(tmp-ht[j-1]*pw[len[i]]%mod+mod)%mod;
            // cout<<i<<' '<<j<<' '<<len[i]<<' '<<tmp<<' '<<s[i][0]<<endl;
            // cout<<tmp<<'*'<<s[i][0]<<endl;
            if(tmp==s[i][0] && (ht[lt-1]-s[i][0]*pw[lt-j-len[i]]%mod+mod+s[i][1]*pw[lt-j-len[i]]%mod)%mod==ht2){
                ans++;
                // cout<<i<<' '<<j<<' '<<j+len[i]-1<<endl;
            }
        }
    }
    return ans;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    pw[0]=1;
    for(int i=1;i<=2001;i++){
        pw[i]=pw[i-1]*p%mod;
        // cout<<pw[i]<<' ';
    }
    // cout<<endl;
    cin>>n>>q;
    string tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        s[i][0]=hsh(tmp);
        cin>>tmp;
        s[i][1]=hsh(tmp);
        len[i]=tmp.size();
    }
    // for(int i=1;i<=n;i++){
    //     cout<<s[i][0]<<' '<<s[i][1]<<endl;
    // }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        if(t1.size()!=t2.size()) cout<<0<<endl;
        else cout<<solve()<<endl;
    }
    return 0;
}