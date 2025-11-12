#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr first
#define sc second
#define pii pair<int,int>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define ro(i,r,l) for(inr i=r;i>=l;i--)
const int N=2e5+5,L=5e6+5,M=1949100103;
int qpow(int n,int m){
    int s=n,rs=1;
    while (m){
        if (m&1)
            rs=rs*s%M;
        m>>=1,s=s*s%M;
    }
    return rs;
}
const int invB=qpow(131,M-2);
int n,m,B[N],iB[N],hst[2][L];
vector<int>hsh[2][N];
string s[2][N],t[2];
int gethsh(int x,int y,int l,int r){
    if (l>r||r>=s[x][y].size())
        return -1;
    int hsl,hsr=hsh[x][y][r];
    if (l==0) hsl=0;
    else hsl=hsh[x][y][l-1];
    int rs=(hsr-hsl+M)%M*iB[l]%M;
    return rs;
}
int gethst(int x,int l,int r){
    if (l>r||r>=t[x].size())
        return -1;
    int hsl,hsr=hst[x][r];
    if (l==0) hsl=0;
    else hsl=hst[x][l-1];
    // cerr<<hsl<<' '<<hsr<<'\n';
    int rs=(hsr-hsl+M)%M*iB[l]%M;
    return rs;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    B[0]=iB[0]=1;
    // cout<<133*invB%M<<'\n';
    fo(i,1,N-1){
        B[i]=B[i-1]*131%M;
        iB[i]=iB[i-1]*invB%M;
    }
    fo(i,1,n){
        cin>>s[0][i]>>s[1][i];
        int hs=0;
        fo(j,0,(int)s[0][i].size()-1){
            (hs+=B[j]*(s[0][i][j]-'a')%M)%=M;
            hsh[0][i].push_back(hs);
            // cerr<<hs<<' ';
        }
        // cerr<<'\n';
        hs=0;
        fo(j,0,(int)s[1][i].size()-1){
            (hs+=B[j]*(s[1][i][j]-'a')%M)%=M;
            hsh[1][i].push_back(hs);
            // cerr<<hs<<' ';
        }
        // cerr<<'\n';
    }
    fo(i,1,m){
        cin>>t[0]>>t[1];
        int l=1e9,r=0,rs=0;
        fo(j,0,(int)t[0].size()-1)
            if (t[0][j]!=t[1][j])
                l=min(l,j),r=j;
        fo(j,0,(int)t[0].size()-1){
            hst[0][j]=hst[1][j]=0;
            (hst[0][j]+=B[j]*(t[0][j]-'a')%M)%=M;
            (hst[1][j]+=B[j]*(t[1][j]-'a')%M)%=M;
            if (j) (hst[0][j]+=hst[0][j-1])%=M;
            if (j) (hst[1][j]+=hst[1][j-1])%=M;
            // cerr<<hst[0][j]<<' ';
        }
        // cerr<<'\n';
        // cerr<<l<<' '<<r<<' '<<gethst(0,l,r)<<'\n';
        fo(i,1,n)
            fo(j,0,(int)s[0][i].size()){
                // cerr<<j<<' '<<gethsh(0,i,j,j+(r-l))<<' '<<gethst(0,l,r)<<'\n';
                if (gethsh(0,i,j,j+(r-l))!=gethst(0,l,r))
                    continue;
                if (gethsh(1,i,j,j+(r-l))!=gethst(1,l,r))
                    continue;
                if (j){
                    if (gethsh(0,i,0,j-1)!=gethst(0,l-j,l-1))
                        continue;
                    if (gethsh(1,i,0,j-1)!=gethst(1,l-j,l-1))
                        continue;
                }
                if (j+(r-l)!=(int)s[0][i].size()-1){
                    int len=(int)s[0][i].size()-1-(j+(r-l));
                    if (gethsh(0,i,j+(r-l)+1,j+(r-l)+len)!=gethst(0,r+1,r+len))
                        continue;
                    if (gethsh(1,i,j+(r-l)+1,j+(r-l)+len)!=gethst(1,r+1,r+len))
                        continue;
                }
                rs++;
            }
        cout<<rs<<'\n';
    }
    return 0;
}
/*
这样冷冰冰的结局，人家可不喜欢哦～

于是……
*/