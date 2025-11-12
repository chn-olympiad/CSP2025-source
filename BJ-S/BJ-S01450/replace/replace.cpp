#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=5e6+99,e=31,mod=1e9+9;
#define FOR(i,l,r) for(int i=(int)(l);i<=(int)(r);++i)
#define FER(i,r,l) for(int i=(int)(r);i>=(int)(l);--i)
int n,m;
int h;
int pp[N];
int a[2][N];
unordered_set<int>st;
unordered_map<int,unordered_map<int,int>>mp;
int run(const string&s){
    ll k=0;
    FER(i,s.size()-1,0)k=(k*e+s[i]-'a'+1)%mod;
    return k;
}
int hashs(int w[],int l,int r){
    return (l>r)?0:int((0ll+w[l]-1ll*pp[r-l+1]*w[r+1]%mod+mod)%mod);
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    pp[0]=1;
    FOR(i,1,N)pp[i]=1ll*pp[i-1]*e%mod;
    FOR(i,1,n){
        string s[2];
        cin>>s[0]>>s[1];
        st.insert(s[0].size());
        ++mp[run(s[0])][run(s[1])];
    }
    FOR(j,1,m){
        string t[2];
        cin>>t[0]>>t[1];
        FOR(i,0,1){
            a[i][t[0].size()]=0;
            FER(j,t[0].size()-1,0)a[i][j]=(1ll*a[i][j+1]*e+t[i][j]-'a'+1)%mod;
        }
        int m=t[0].size();
        ll ans(0);
        FOR(i,0,m-1){
            if(hashs(a[0],0,i-1)!=hashs(a[1],0,i-1))continue;
            for(auto j:st){
                if(i+j-1<m){
                    if(hashs(a[0],i+j,m)==hashs(a[1],i+j,m))ans+=mp[hashs(a[0],i,i+j-1)][hashs(a[1],i,i+j-1)];
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
