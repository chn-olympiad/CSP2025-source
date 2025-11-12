#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define PII pair<int,int>
#define mkp make_pair
#define fi first
#define se second
//const int N=400024;
int n,q,cnt,mod1=987654319,mod2=705289853,base=131;
string s1,s2,t1,t2,S,T;
gp_hash_table<int,int> mp;
int hsh(int x,int y){
    return x*1e9+y;
}
void work(){
    int len=s1.size(),l=0,r=len-1;
    for(int i=0;i<len;i++){
        if(s1[i]!=s2[i]){
            l=i;
            break;
        }
    }
    for(int i=len-1;i>=0;i--){
        if(s1[i]!=s2[i]){
            r=i;
            break;
        }
    }
    S.resize(len+r-l+1 + 3);
    int cnt=0;
    for(int i=0;i<l;i++){
        S[cnt++]=s1[i];
    }
    S[cnt++]='A';
    for(int i=l;i<=r;i++){
        S[cnt++]=s1[i];
    }
    S[cnt++]='A';
    for(int i=l;i<=r;i++){
        S[cnt++]=s2[i];
    }
    S[cnt++]='A';
    for(int i=r+1;i<len;i++){
        S[cnt++]=s2[i];
    }
}
void work2(){
    int len=t1.size(),l=0,r=len-1;
    for(int i=0;i<len;i++){
        if(t1[i]!=t2[i]){
            l=i;
            break;
        }
    }
    for(int i=len-1;i>=0;i--){
        if(t1[i]!=t2[i]){
            r=i;
            break;
        }
    }
    T.resize(len+r-l+1 + 3);
    int cnt=0;
    for(int i=0;i<l;i++){
        T[cnt++]=t1[i];
    }
    T[cnt++]='A';
    for(int i=l;i<=r;i++){
        T[cnt++]=t1[i];
    }
    T[cnt++]='A';
    for(int i=l;i<=r;i++){
        T[cnt++]=t2[i];
    }
    T[cnt++]='A';
    for(int i=r+1;i<len;i++){
        T[cnt++]=t2[i];
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        work();
        int hsh1=0,hsh2=0;
        for(int j=0;j<S.size();j++){
            hsh1=(hsh1*base+S[j])%mod1;
            hsh2=(hsh1*base+S[j])%mod2;
        }
        mp[hsh(hsh1,hsh2)]++;
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<0<<"\n";
            continue;
        }
        work2();
        int ans=0;
        for(int k=0;k<T.size();k++){
            int hsh1=0,hsh2=0;
            for(int j=k;j<T.size();j++){
                hsh1=(hsh1*base+T[j])%mod1;
                hsh2=(hsh1*base+T[j])%mod2;
                ans+=mp[hsh(hsh1,hsh2)];
            }
        }
        cout<<ans<<"\n";
    }
}
//hao wo hui le,zhe bu jiu shi ac zi dong ji ma!
//dan shi wang le,ha ha
//wen hua ke hai ren bu qian!!!
//ni dou zhe me kao le
//na wo zhe fen bu na bu jiu de le
//ei,SA shi bu shi ye xing
//zhe ge ye wang le...