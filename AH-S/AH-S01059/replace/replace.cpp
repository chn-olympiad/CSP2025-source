#include<iostream>
#include<cstdio>
#include<vector>
#define M 5000005
#define ll long long
#define N 200005
using namespace std;
ll tot;
struct node{
    int son[26],fail,nxt;
}trie[M];
int nxt[N];
ll s11[N],s21[N],ans;
ll t11[N],t21[N],Base1=998244353,P1=1e9+9;
string s1[N],s2[N],t1[N],t2[N];
vector<int> g[N];
void init(int x){
    g[x].push_back(-1);
    for(int i=1,j=-1;i<s1[x].size();i++){
        while(j!=-1&&s1[x][i]!=s1[x][j+1]){
            j=g[x][j];
        }
        if(s1[x][i]==s1[x][j+1])
            j++;
        g[x].push_back(j);
    }
}
ll qp(ll a,ll b,ll p){
    if(b==0) return 1ll;
    ll x=qp(a*a%p,b/2,p);
    return b%2?x*a%p:x;
}
ll calc(int a,int b,int c){
    ll cur=t11[c];
    return (cur-qp(Base1,b,P1)*(s11[a]-s21[a]+P1)%P1+P1)%P1;
}
void kmp(int x,int y){
    for(int i=0,j=-1;i<t1[y].size();i++){
        while(j!=-1&&t1[y][i]!=s1[x][j+1]){
            j=g[x][j];
        }
        if(t1[y][i]==s1[x][j+1]){
            j++;
            if(j==s1[x].size()-1){
                ll h=calc(x,t1[y].size()-1-i,y);
                if(h==t21[y]){
                    ans++;
                }
                j=g[x][j];
            }
        }
    }
}
int n,m;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        init(i);
        //if(s1[i]=="l"&&s2[i]=="p") cout<<i<<endl;
    }
    for(int i=1;i<=n;i++){
        ll ret=0;
        for(int j=0;j<s2[i].size();j++){
            ret=(ret*Base1+s2[i][j]-'a'+1)%P1;
        }
        s21[i]=ret;
        ret=0;
        for(int j=0;j<s1[i].size();j++){
            ret=(ret*Base1+s1[i][j]-'a'+1)%P1;
        }
        s11[i]=ret;
    }
    //cout<<"$$$$$$$$$$$"<<trie[3].fail<<endl;
    for(int i=1;i<=m;i++) cin>>t1[i]>>t2[i];
    for(int i=1;i<=m;i++){
        ll ret=0;
        for(int j=0;j<t2[i].size();j++){
            ret=(ret*Base1+t2[i][j]-'a'+1)%P1;
        }
        t21[i]=ret;
        ret=0;
        for(int j=0;j<t1[i].size();j++){
            ret=(ret*Base1+t1[i][j]-'a'+1)%P1;
        }
        t11[i]=ret;
    }
    for(int i=1;i<=m;i++){
        ans=0;
        for(int j=1;j<=n;j++){
            kmp(j,i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
