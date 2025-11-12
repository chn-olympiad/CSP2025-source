#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ppb pop_back
using namespace std;

int n,q;

string s1[200100],s2[200100],t1[200100],t2[200100];
int cg[200100],pre[200100],lst[200100];
void solve1(){
    for(int i=1;i<=q;++i){
        int len1=t1[i].size(),len2=t2[i].size();
        ll ans=0;
        if(len1!=len2){
            cout<<0<<'\n';
            continue;
        }
        for(int p=0;p<len1;++p){
            for(int k=1;k<=n;++k){
                if(s1[k][0]==t1[i][p])
                {
                    bool ok=1;
                    for(int j=0;j<s1[k].size();++j){
                        if(t1[i][p+j]!=s1[k][j]) {ok=0;break;} 
                        if(s2[k][j]!=t2[i][p+j]) {ok=0;break;}
                    }
                    if(ok==0) continue;
                    for(int j=p+s1[k].size();j<len1;++j){
                        if(t1[i][j]!=t2[i][j]) {ok=0;break;}
                        // else cout<<"tuwalu\n";
                    }
                    if(ok==1) {
                        ++ans;
                        // cout<<p<<' '<<s1[k]<<' '<<s2[k]<<'\n';
                    }
                }
            }
            if(t1[i][p]!=t2[i][p]) break;
        }
        cout<<ans<<'\n';
    }
    exit(0);
}
void solve2(){
    for(int i=1;i<=n;++i){
        int p1,p2;
        for(int p=0;p<s1[i].size();++p){
            if(s1[i][p]=='b') p1=p,pre[i]=p,lst[i]=s1[i].size()-p-1;
            if(s2[i][p]=='b') p2=p;
        }
        cg[i]=p1-p2;
    }
    for(int i=1;i<=q;++i){
        int d1,d2;
        ll ans=0;
        int len1=t1[i].size(),len2=t2[i].size();
        if(len1!=len2){
            cout<<0<<'\n';
            continue;
        }
        for(int p=0;p<len1;++p){
            if(t1[i][p]=='b') d1=p;
            if(t2[i][p]=='b') d2=p;
        }
        for(int j=1;j<=n;++j){
            if(d1-d2==cg[j]&&d1>=pre[j]&&len1-d1-1>=lst[j])
                ++ans;
        }
        cout<<ans<<'\n';
    }
    exit(0);
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    ll l1=0,l2=0;
    for(int i=1;i<=n;++i){
        cin>>s1[i]>>s2[i];
        l1+=(s1[i].size()+s2[i].size());
    }
    for(int i=1;i<=q;++i){
        cin>>t1[i]>>t2[i];
        l2+=(t1[i].size()+t2[i].size());
    }
    // solve1();
    if(n<=1000&&q<=1000&&l1<=2000&&l2<=2000)
        solve1();
    else if(n<=1000&&q<=1000&&l1<=1000000&&l2<=1000000)
        solve2();
    else if(n<=10000&&q<=10000&&l1<=1000000&&l2<=1000000)
        solve1();
    else 
        solve2();
    return 0;
}