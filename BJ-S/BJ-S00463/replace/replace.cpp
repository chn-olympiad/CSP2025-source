#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef unsigned long long ull;
template<typename T>
void chkmin(T &x,const T &y){x=min(x,y);}
template<typename T>
void chkmax(T &x,const T &y){x=max(x,y);}
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3f;
const int MOD=998244353;
void add(int &x,int y){
    x+=y;
    if(x>=MOD) x-=MOD;
}
int qpow(int a,ll b){
    int mul=1;
    while(b){
        if(b&1) mul=(ll)mul*a%MOD;
        a=(ll)a*a%MOD;
        b>>=1;
    }
    return mul;
}
const int N=200005,B=2237;
int n,q,vis[N];
string s[N][2],t[N][2];
unordered_map<ull,vector<int>> mp1,mp3;
unordered_map<ull,unordered_map<ull,vector<int>>> mp2;
int main(){
    #ifndef JZQ
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        int l=s[i][0].size(),r=0;
        for(int j=0;j<s[i][0].size();j++) if(s[i][0][j]!=s[i][1][j]) chkmin(l,j),chkmax(r,j);
        ull hsh=0;
        for(int j=l-1;j>=0;j--) hsh=hsh*B+s[i][0][j];
        mp1[hsh].push_back(i);
        hsh=0;
        for(int j=r+1;j<s[i][0].size();j++) hsh=hsh*B+s[i][0][j];
        mp3[hsh].push_back(i);
        ull hsh1=0,hsh2=0;
        for(int j=l;j<=r;j++) hsh1=hsh1*B+s[i][0][j],hsh2=hsh2*B+s[i][1][j];
        mp2[hsh1][hsh2].push_back(i);
    }
    for(int i=1;i<=q;i++){
        cin>>t[i][0]>>t[i][1];
        if(t[i][0].size()!=t[i][1].size()){
            cout<<'0'<<'\n';
            continue;
        }
        int l=t[i][0].size(),r=0;
        for(int j=0;j<t[i][0].size();j++) if(t[i][0][j]!=t[i][1][j]) chkmin(l,j),chkmax(r,j);
        for(int i=1;i<=n;i++) vis[i]=0;
        ull hsh=0;
        for(auto i:mp1[0]) vis[i]++/*,printf("%d ",i)*/;
        for(int j=l-1;j>=0;j--){
            hsh=hsh*B+t[i][0][j];
            for(auto i:mp1[hsh]) vis[i]++/*,printf("%d ",i)*/;
        }
        // printf("\n");
        hsh=0;
        for(auto i:mp3[0]) vis[i]++/*,printf("%d ",i)*/;
        for(int j=r+1;j<t[i][0].size();j++){
            hsh=hsh*B+t[i][0][j];
            for(auto i:mp3[hsh]) vis[i]++/*,printf("%d ",i)*/;
        }
        // printf("\n");
        ull hsh1=0,hsh2=0;
        for(int j=l;j<=r;j++) hsh1=hsh1*B+t[i][0][j],hsh2=hsh2*B+t[i][1][j];
        int cnt=0;
        // printf("duck %llu %llu\n",hsh1,hsh2);
        for(auto i:mp2[hsh1][hsh2]){
            // printf("%d(%d) ",i,vis[i]);
            if(vis[i]==2) cnt++;
        }
        // printf("\n");
        cout<<cnt<<'\n';
    }
    return 0;
}