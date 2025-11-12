#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const ull base=131;
const int N=1e6+10;
ull hs[2][N],mi[N];
ull Hash(ull *hs,int l,int r){
    if(l>r)return 0;
    return hs[r]-mi[r-l+1]*hs[l-1];
}
int n,q;
int len[2][N];
string s[2];
ull HS[2][N];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>n>>q;
    mi[0]=1;
    for(int i=1;i<N;++i)mi[i]=mi[i-1]*base;
    for(int i=1;i<=n;++i){
        cin>>s[0]>>s[1];
        len[0][i]=s[0].size();
        len[1][i]=s[1].size();
        s[0]=" "+s[0];
        s[1]=" "+s[1];
        for(int x=1;x<=len[0][i];++x)hs[0][i]=hs[0][i]*base+s[0][x];
        for(int x=1;x<=len[1][i];++x)hs[1][i]=hs[1][i]*base+s[1][x];
    }
    while(q--){
        int tmp=0;
        string s1,s2;cin>>s1>>s2;
        int L=s1.size();
        s1=" "+s1,s2=" "+s2;
        for(int i=1;i<=L;++i){
            HS[0][i]=HS[0][i-1]*base+s1[i];
            HS[1][i]=HS[1][i-1]*base+s2[i];
        }
        for(int i=1;i<=n;++i){
            for(int pos=1;pos+len[0][i]-1<=L;++pos){
                if(Hash(HS[0],1,pos-1)==Hash(HS[1],1,pos-1) && Hash(HS[0],pos+len[0][i],L)==Hash(HS[1],pos+len[0][i],L) && Hash(HS[0],pos,pos+len[0][i]-1)==hs[0][i] && Hash(HS[1],pos,pos+len[1][i]-1)==hs[1][i]){
                    ++tmp;
                }
            }
        }
        cout<<tmp<<'\n';
    }
    return 0;
}