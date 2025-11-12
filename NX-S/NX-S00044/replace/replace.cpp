// CSPS2025 - replace
// Alea(322792)
#include <bits/stdc++.h>
using namespace std;
ifstream fin("replace.in");
ofstream fout("replace.out");
// Only for subtask AB and n<=100
typedef long long ll;
const int N=5e6+5;
int n,q;
string s[(int)(2e5+5)][2];
// done
namespace subtaskB{
    vector<pair<int,int>> mov[N*2];
    void solve(){
        for(int i=0;i<N*2;++i) mov[i].clear();
        for(int i=1;i<=n;++i){
            int L=s[i][0].size(),e[2]={0,0};
            for(int j=0;j<L;++j){
                if(s[i][0][j]=='b') e[0]=j;
                if(s[i][1][j]=='b') e[1]=j;
            }
            mov[e[1]-e[0]+N].push_back({e[0],L});
        }
        while(q--){
            string t0,t1;
            fin>>t0>>t1;
            int h[2]={0,0},l=t0.size(),ans=0;
            for(int i=0;i<l;++i){
                if(t0[i]=='b') h[0]=i;
                if(t1[i]=='b') h[1]=i;
            }
            for(auto ie:mov[h[1]-h[0]+N]) if(h[0]>=ie.first&&h[0]-ie.first+ie.second<=l) ++ans;
            fout<<ans<<endl;
        }
    }
};
namespace otherwise{
    const ll p=29,Q=998244353;
    ll hv[(int)(2e5+5)][2],hsh[2][N];
    void init(string &s,int x){
        int l=s.size();hsh[x][0]=0;
        for(int i=0;i<l;++i) hsh[x][i+1]=(hsh[x][i]*p%Q+s[i]-'a'+1)%Q;
        for(int i=0;i<l;++i) hsh[x][i]=hsh[x][i+1];
    }
    ll pw(ll a,ll n,ll Q){
        ll ans=1;
        for(a%=Q;n;n>>=1,a=a*a%Q) if(n&1) ans=ans*a%Q;
        return ans;
    }
    ll H(int l,int r,int x){
        if(l==0) return hsh[x][r];
        else return (hsh[x][r]-(pw(p,r-l+1,Q)*hsh[x][l-1]%Q)+Q)%Q;
    }
    void solve(){
        vector<pair<int,pair<ll,ll>>> aya;
        for(int i=1,L;i<=n;++i){
            init(s[i][0],0),init(s[i][1],1),L=s[i][0].size();
            aya.push_back({L-1,{hsh[0][L-1],hsh[1][L-1]}});
        }
        sort(aya.begin(),aya.end());
        while(q--){
            string t[2];
            fin>>t[0]>>t[1];
            int l=t[0].size()-1,ans=0;
            init(t[0],0),init(t[1],1);
            for(int i=0;i<=l;++i) for(auto ie:aya){
                ll L=ie.first,h0=ie.second.first,h1=ie.second.second;
                if(i+L>l) continue;
                if(H(i,i+L,0)==h0&&H(i,i+L,1)==h1) ++ans;
            }
            fout<<ans<<endl;
        }
    }
};
int main(){
    bool foB=1;
    fin>>n>>q;
    for(int i=1;i<=n;++i){
        fin>>s[i][0]>>s[i][1];
        int b[2]={0,0},l=s[i][0].length();
        for(int j=0;foB&&j<2;++j){
            for(int k=0;foB&&k<l;++k){
                if(s[i][j][k]!='a'&&s[i][j][k]!='b'){
                    foB=0;
                    break;
                }
                b[j]+=(s[i][j][k]=='b');
            }
            if(b[j]!=1) foB=0;
        }
    }
    if(foB) subtaskB::solve();
    else otherwise::solve();
    return 0;
}