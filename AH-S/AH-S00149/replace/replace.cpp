#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s1[200005],s2[200005];
long long l1[200005],l2[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        for(long long oi=0;oi<s1[i].size();oi++){
            if(s1[i][oi]=='b'){
                l1[i]=oi;
            }
        }
        for(long long oi=0;oi<s2[i].size();oi++){
            if(s2[i][oi]=='b'){
                l2[i]=oi;
            }
        }
    }
    while(m--){
        long long ans=0;
        string l,r;
        cin>>l>>r;
        if(l.size()!=r.size()){
            printf("%lld\n",0);
        }
        long long ll,rl;
        for(long long oi=0;oi<l.size();oi++){
            if(l[oi]=='b'){
                ll=oi;
            }
        }
        for(long long oi=0;oi<r.size();oi++){
            if(r[oi]=='b'){
                rl=oi;
            }
        }
        for(long long i=1;i<=n;i++){
            if(rl>=ll&&rl-ll==l2[i]-l1[i]&&ll>=l1[i]&&s2[i].size()-l2[i]<=r.size()-rl){
                ans++;
            }
            if(rl<ll&&ll-rl==l1[i]-l2[i]&&ll>=l1[i]&&s2[i].size()-l2[i]<=r.size()-rl){
                ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
