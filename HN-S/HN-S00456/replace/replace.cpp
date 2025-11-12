#include <bits/stdc++.h>
#define lint __int128
#define int long long
#define fi first
#define se second
#define Il inline
#define vec vector
#define pb push_back
#define IT ::iterator
#define p_q priority_queue

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef double db;
const int N=3e6,mod=909119191;
const db eps=1e-9;

// bool P1;

int n,Q,m[N+5],h1[N+5],h2[N+5],ha[N+5],hb[N+5],pw[N+5];
string s1,s2;

Il int hs1(int l,int r){
    if(l>r)return 0;
    return (ha[r]-ha[l-1]*pw[r-l+1]%mod+mod)%mod;
}

Il int hs2(int l,int r){
    if(l>r)return 0;
    return (hb[r]-hb[l-1]*pw[r-l+1]%mod+mod)%mod;
}

// bool P2;

signed main(){
    // system("diff replace3.ans replace.out -Z");return 0;
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // cout<<abs((&P1)-(&P2))/1024/1024;return 0;
    pw[0]=1;
    for(int i=1;i<=N;i++){
        pw[i]=pw[i-1]*131%mod;
    }
    cin>>n>>Q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2,m[i]=s1.size();s1=" "+s1,s2=" "+s2;
        for(int j=1;j<=m[i];j++){
            h1[i]=(h1[i]*131+(s1[j]-'a'+1))%mod,h2[i]=(h2[i]*131+(s2[j]-'a'+1))%mod;
        }
    }
    while(Q--){
        cin>>s1>>s2;
        if(s1.size()!=s2.size()){
            cout<<"0\n";
            continue;
        }
        int t=s1.size(),l=0,r=0;s1=" "+s1,s2=" "+s2;
        for(int i=1;i<=t;i++){
            ha[i]=(ha[i-1]*131+(s1[i]-'a'+1))%mod,hb[i]=(hb[i-1]*131+(s2[i]-'a'+1))%mod;
            if(s1[i]!=s2[i]){
                if(!l){
                    l=i;
                }
            }
        }
        while(r<=t&&hs1(r+1,t)!=hs2(r+1,t)){
            r++;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=l&&j+m[i]-1<=t;j++){
                if(j+m[i]-1>=r&&hs1(j,j+m[i]-1)==h1[i]&&hs2(j,j+m[i]-1)==h2[i]){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}