#include<bits/stdc++.h>
using namespace std;
const int NR=5e6+5;
const uint64_t P=127;
int n,q;
unordered_map<uint64_t,unordered_map<uint64_t,int>> f;
uint64_t sa[NR],sb[NR],p[NR];
uint64_t Hash(const string& s){
    uint64_t ret=0;
    for(int i=0;i<s.size();i++){
        ret=ret*P+s[i];
    }
    return ret;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0),cout.tie(0);
    p[0]=1;
    for(int i=1;i<=5e6;i++){
        p[i]=p[i-1]*P;
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        f[Hash(a)][Hash(b)]++;
    }
    while(q--){
        string a,b;
        cin>>a>>b;
        sa[0]=0;
        for(int i=1;i<=a.size();i++){
            sa[i]=sa[i-1]*P+a[i-1];
        }
        sb[0]=0;
        for(int i=1;i<=b.size();i++){
            sb[i]=sb[i-1]*P+b[i-1];
        }
        long long ans=0;
        for(int l=1;l<=a.size();l++){
            for(int len=1;l+len-1<=a.size();len++){
                int r=l+len-1;
                uint64_t t1=sa[r]-sa[l-1]*p[r-l+1];
                uint64_t t2=sb[r]-sb[l-1]*p[r-l+1];
                if(sa[a.size()]-t1*p[a.size()-r]+t2*p[a.size()-r]==sb[b.size()]){
                    ans+=f[t1][t2];
                    //printf("ASD%d %d\n",l,r);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
