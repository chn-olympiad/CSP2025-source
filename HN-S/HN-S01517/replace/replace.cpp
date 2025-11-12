#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=1e9+7;
int n,q,l,r,nxt[5000005],nex[5000005],bs[5000005],hshs[200005],hsht[5000005];
string s1[200005],s2[200005],t1,t2;
int queryt(int l,int r){
    if(l<1||r>=t1.size())return -1;
    return (hsht[r]-hsht[l-1]*bs[r-l+1]%mod+mod)%mod;
}
bool check(int id){
    if(s1[id].size()<r-l+1)return 0;
    nxt[1]=0;int n=s1[id].size()-1,m=t1.size()-1;
    for(int i=2,j=0;i<=n;i++){
        while(j&&(s1[id][j+1]!=s1[id][i]||s2[id][j+1]!=s2[id][i]))j=nxt[j];
        if(s1[id][j+1]==s1[id][i]&&s2[id][j+1]==s2[id][i])j++;
        nxt[i]=j;
    }
    for(int i=1,j=0;i<=m;i++){
        while(j&&(s1[id][j+1]!=t1[i]||s2[id][j+1]!=t2[i]))j=nxt[j];
        if(s1[id][j+1]==t1[i]&&s2[id][j+1]==t2[i])j++;
        if(j==n){
            if(i>=r&&i-n+1<=l)return 1;
            j=nxt[j];
        }
    }
    return 0;
}
bool check2(int id){
    int n=s1[id].size();
    for(int i=1,j=0;i<=n;i++){
        while(j&&(t1[j+l]!=s1[id][i]||t2[j+l]!=s2[id][i]))j=nex[j];
        if(t1[j+l]==s1[id][i]&&t2[j+l]==s2[id][i])j++;
        if(j==r-l+1){
            if(hshs[id]==queryt(r-i+1,r+n-i-1))return 1;
            j=nex[j];
        }
    }
    return 0;
}
void solve1(){
    bs[0]=1;
    for(int i=1;i<=5000000;i++)bs[i]=bs[i-1]*131%mod;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        int len=s1[i].size();
        s1[i]=' '+s1[i],s2[i]=' '+s2[i];
        for(int j=1;j<=len;j++)hshs[i]=(hshs[i]*131+((s1[i][j]-'a')*26+(s2[i][j]-'a')))%mod;
    }
    cin>>t1>>t2;int len=t1.size(),ans=0;t1=' '+t1,t2=' '+t2;
    if(t1.size()!=t2.size()){cout<<"0\n";return;}
    for(int i=1;i<=len;i++)hsht[i]=(hsht[i-1]*131+((t1[i]-'a')*26+(t2[i]-'a')))%mod;
    for(l=1;l<=len;l++)if(t1[l]!=t2[l])break;
    for(r=len;r;r--)if(t1[r]!=t2[r])break;
    nex[1]=0;
    for(int i=l+1,j=0;i<=r;i++){
        while(j&&(t1[j+l]!=t1[i]||t2[j+l]!=t2[i]))j=nex[j];
        if(t2[j+l]==t2[i]&&t2[j+l]==t2[i])j++;
        nex[i-l+1]=j;
    }
    for(int i=1;i<=n;i++)if(check2(i))ans++;
    cout<<ans;
}
void solve2(){
    for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i],s1[i]=' '+s1[i],s2[i]=' '+s2[i];
    while(q--){
        cin>>t1>>t2;int len=t1.size(),ans=0;t1=' '+t1,t2=' '+t2;
        if(t1.size()!=t2.size()){cout<<"0\n";continue;}
        for(l=1;l<=len;l++)if(t1[l]!=t2[l])break;
        for(r=len;r;r--)if(t1[r]!=t2[r])break;
        for(int i=1;i<=n;i++)if(check(i))ans++;
        cout<<ans<<'\n';
    }
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>q;
    if(q==1)solve1();
    else if(n<=1000)solve2();
    return 0;
}