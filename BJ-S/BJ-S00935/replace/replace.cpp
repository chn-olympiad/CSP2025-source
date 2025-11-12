#include <bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
#define endl "\n"
#define print(x) cerr<<#x<<"="<<x<<"\n"
#define dbg() cerr<<"LINE "<<__LINE__<<"\n"
#define empb emplace_back
using namespace std;
const int mod=998244353,p=131;
inline int Mod(int x){
    x%=mod;
    if(x<0)x+=mod;
    return x;
}
int n,q,p1[222222],p2[222222],pre[222222];//第一次改变的位置
struct Rep{//置换
    string x,y;
}a[222222];
vector<int> hx[222222],hy[222222],hs[222222],ht[222222];//哈希值
string s[222222],t[222222];//询问
bool IS_CASE_B=1;
bool isspecial(string ss){
    int cnta=0,cntb=0;
    for(auto x:ss){
        if(x==' ')continue;
        if(x=='a')cnta++;
        else if(x=='b') cntb++;
        else{
            return 0;
        }
    }
    return cntb==1;
}
int geths(int x,int l,int r){
    if(l>r)return 0;
    return Mod(hs[x][r]-Mod(hs[x][l-1]*pre[r-l+1]));
}
int getht(int x,int l,int r){
    if(l>r)return 0;
    return Mod(ht[x][r]-Mod(ht[x][l-1]*pre[r-l+1]));
}
bool judge(int x,int y,int pos){//x号置换y号询问，置换起始位置pos
    //cout<<"judge:op="<<x<<" query="<<y<<" pos="<<pos<<"\n";
    int lenR=a[x].x.size()-1,lenQ=s[y].size()-1;
    //cout<<"Len of op="<<lenR<<" Len of query="<<lenQ<<"\n";
    if(pos<1||pos+lenR-1>lenQ){
        //cout<<"Out of range\n";
        return 0;
    }
    if(geths(y,pos,pos+lenR-1)!=hx[x][lenR]){
        //cout<<"Unmatched hash value pre-operation:"<<geths(y,pos,pos+lenR-1)<<"(query)!="<<hx[x][lenR]<<"(op)\n";
        return 0;
    }
    if(getht(y,pos,pos+lenR-1)!=hy[x][lenR]||geths(y,1,pos-1)!=getht(y,1,pos-1)||geths(y,pos+lenR,lenQ)!=getht(y,pos+lenR,lenQ)){
        //cout<<"Unmatched hash value post-operation:"<<getht(y,pos,pos+lenR-1)<<"(query)!="<<hy[x][lenR]<<"(op)\n";
        return 0;
    }
    return 1;
}
void solveB(){
    //cerr<<"Special Case B detected!";
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<a[i].x.size();j++){
            if(a[i].x[j]=='b'){
                fstb1[i]=j;
            }
        }
    }
    for(int i=1;i<=q;i++){
        for(int j=1;j<s[i].size();j++){
            if(s[i][j]=='b'){
                fstb2[i]=j;
            }
        }
        for(int j=1;j<t[i].size();j++){

        }
    }*/
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pre[0]=1;
    for(int i=1;i<222222;i++){
        pre[i]=Mod(pre[i-1]*p);
    }
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].x=" "+a[i].x;
        a[i].y=" "+a[i].y;
        hx[i].empb(0);
        for(int j=1;j<a[i].x.size();j++){
            hx[i].empb(Mod(Mod(hx[i][j-1]*p)+a[i].x[j]-'a'+1));
        }
        hy[i].empb(0);
        for(int j=1;j<a[i].y.size();j++){
            hy[i].empb(Mod(Mod(hy[i][j-1]*p)+a[i].y[j]-'a'+1));
        }
        if(!isspecial(a[i].x)||!isspecial(a[i].y))IS_CASE_B=0;
        for(int j=1;j<a[i].x.size();j++){
            if(a[i].y[j]!=a[i].x[j]){
                p1[i]=j;
                break;
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>s[i]>>t[i];
        s[i]=" "+s[i];
        t[i]=" "+t[i];
        hs[i].empb(0);
        for(int j=1;j<s[i].size();j++){
            hs[i].empb(Mod(Mod(hs[i][j-1]*p)+s[i][j]-'a'+1));
        }
        ht[i].empb(0);
        for(int j=1;j<t[i].size();j++){
            ht[i].empb(Mod(Mod(ht[i][j-1]*p)+t[i][j]-'a'+1));
        }
        if(!isspecial(s[i])||!isspecial(t[i]))IS_CASE_B=0;
        for(int j=1;j<s[i].size();j++){
            if(t[i][j]!=s[i][j]){
                p2[i]=j;
                break;
            }
        }
    }
    if(IS_CASE_B){
        solveB();
        //return 0;
    }
    /*cout<<"hs:\n";
    for(int i=1;i<=q;i++){
        for(int j=1;j<s[i].size();j++){
            cout<<hs[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    for(int i=1;i<=q;i++){
        //if(i!=1)continue;
        int ans=0;
        for(int j=1;j<=n;j++){
            //cout<<"Main:Query "<<i<<" ,Operation "<<j<<"\n";
            if(judge(j,i,p2[i]-p1[j]+1)){
                ans++;
                //cout<<"Succeed\n";
            }
            else{
                //cout<<"Fail\n";
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
