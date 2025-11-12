#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string s1[200005],s2[200005];
string t1[200005],t2[200005];
const int mod1=998244353,mod2=1e9+7;
const int base1=31,base2=29;
map<pair<int,int>,int> hsh1,hsh2;
void gethsh(string s,int &res1,int &res2){
    res1=res2=0;
    for(int i:s){
        res1=(res1*base1+i)%mod1;
        res2=(res2*base2+i)%mod2;
    }
}
int pw1[5000005],pw2[5000005];
void init(string s,int h1[],int h2[]){
    h1[0]=h2[0]=s[0];
    int len=(int)s.length();
    for(int i=1;i<len;i++){
        h1[i]=(h1[i-1]*base1+s[i])%mod1;
        h2[i]=(h2[i-1]*base2+s[i])%mod2;
    }
}
int h1[5000005],h2[5000005],h3[5000005],h4[5000005];
const int V=5e6;
int gethsh1(int h[],int l,int r){
    if(!l) return h[r];
    return h[r]-h[l-1]*pw1[r-l+1]%mod1;
}
int gethsh2(int h[],int l,int r){
    if(!l) return h[r];
    return h[r]-h[l-1]*pw2[r-l+1]%mod2;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pw1[0]=pw2[0]=1;
    for(int i=1;i<=V;i++){
        pw1[i]=pw1[i-1]*base1%mod1;
        pw2[i]=pw2[i-1]*base2%mod2;
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        int h1,h2,h3,h4;
        gethsh(s1[i],h1,h2);
        gethsh(s2[i],h3,h4);
        hsh1[{h1,h3}]++;
        hsh2[{h2,h4}]++;
    }
    for(int i=1;i<=q;i++){
        cin>>t1[i]>>t2[i];
    }
    for(int i=1;i<=q;i++){
        if(t1[i].length()!=t2[i].length()){
            cout<<"0\n";
            continue;
        }
        int pl=-1,pr=-1,len=(int)t1[i].length();
        for(int j=0;j<len;j++){
            if(t1[i][j]!=t2[i][j]){
                if(pl==-1) pl=j;
                pr=j;
            }
        }
        init(t1[i],h1,h2);
        init(t2[i],h3,h4);
        int ans=0;
        // cout<<pl<<" "<<pr<<"\n";
        for(int l=pl;l>=0;l--){
            for(int r=pr;r<len;r++){
                ans+=min(hsh1[{gethsh1(h1,l,r),gethsh1(h3,l,r)}],
                         hsh2[{gethsh2(h2,l,r),gethsh2(h4,l,r)}]);
                // cout<<l<<" "<<r<<" "<<ans<<"\n";
            }
        }
        cout<<ans<<"\n";
    }
}