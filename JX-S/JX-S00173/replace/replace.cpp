#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+2,M=5e6+2,mod=998244389;
int p[N][2],d[N],sum[M][2],pw[M];
map<pair<int,int>,int> mp[M];
int get(int l,int r,int op){
    if(l>r) return 0;
    return (sum[r][op]-1ll*sum[l-1][op]*pw[r-l+1]%mod+mod)%mod;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s[2];
        cin>>s[0]>>s[1];
        d[i]=s[0].size();
        for(int j=0;j<=1;j++){
            for(int t=0;t<s[j].size();t++){
                p[i][j]=(1ll*p[i][j]*27%mod+(s[j][t]-'a'+1))%mod;
            }
        }
    }
    while(q--){
        for(int i=1;i<=n;i++) mp[d[i]].clear();
        string s[2];
        cin>>s[0]>>s[1];
        if(s[1].size()!=s[0].size()){
            cout<<0<<'\n';
            continue;
        }
        s[0]=" "+s[0],s[1]=" "+s[1],pw[0]=1;
        int l=s[0].size()-1;
        for(int i=1;i<=l;i++){
            for(int j=0;j<=1;j++){
                sum[i][j]=(1ll*sum[i-1][j]*27%mod+(s[j][i]-'a'+1))%mod;
            }
            pw[i]=1ll*pw[i-1]*27%mod;
        }
        for(int i=1;i<=l;i++){
            for(int j=1;j+i-1<=l;j++){
                int t=i+j-1;
                int d1=get(j,t,0),d2=get(j,t,1);
                if(get(t+1,l,0)==get(t+1,l,1)&&sum[j-1][0]==sum[j-1][1]) mp[i][make_pair(d1,d2)]++;
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            if(mp[d[i]].find(make_pair(p[i][0],p[i][1]))==mp[i].end()) continue;
            ans+=mp[d[i]][make_pair(p[i][0],p[i][1])];
        }
        cout<<ans<<'\n';
    }
    return 0;
}