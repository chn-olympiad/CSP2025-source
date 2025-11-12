#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=2e5+10,base=47;
int n,q,l[N];
ull h[N][2],p[N],hh[2][N];
string t1,t2;
inline ull hsh(string s){
    ull res=0;
    for(char ch:s) res=res*base+(ch-'a'+1);
    return res;
}
inline ull get(int id,int l,int len){
    if(!len) return 0;
    return hh[id][l+len-1]-hh[id][l-1]*p[len];
}
int len,R;
inline bool check(int beg,int t){
    if(beg+l[t]-1>len) return 0;
    if(h[t][0]==get(0,beg,l[t])&&h[t][1]==get(1,beg,l[t])&&beg+l[t]>R) return 1;
    return 0;
}
inline int solve(){
    int ans=0;
    len=t1.size();
    for(int i=1;i<=len;i++) hh[0][i]=hh[0][i-1]*base+(t1[i-1]-'a'+1);
    for(int i=1;i<=len;i++) hh[1][i]=hh[1][i-1]*base+(t2[i-1]-'a'+1);
    R=len;
    while(t1[R]==t2[R]&&R) R--;
    R++;
    for(int i=1;i<=len;i++){
        for(int j=1;j<=n;j++) ans+=check(i,j);
        if(t1[i-1]!=t2[i-1]) break;
    }
    return ans;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    p[0]=1;for(int i=1;i<N;i++) p[i]=p[i-1]*base;
    for(int i=1;i<=n;i++){
        string s[2];
        cin>>s[0]>>s[1];l[i]=s[0].size();
        h[i][0]=hsh(s[0]),h[i][1]=hsh(s[1]);
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        cout<<solve()<<"\n";
    }
    return 0;
}