#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
string a[N],b[N];
string t,p;
int ans;
int nxt[N>>1][N];
void getnxt(string s,int x){
    int len=s.size()-1;
    for(int i=2,j=0;i<=len;i++){
        while(j>0&&s[j+1]!=s[i])j=nxt[x][j];
        if(s[j+1]==s[i])j++;
        nxt[x][i]=j;
    }
}
bool check(int u,int v,int x){
    int m=a[x].size()-1;
    string q=t;
    for(int i=1;i<=m;i++){
        q[i+u-1]=b[x][i];
    }
    if(q==p)return 1;
    else return 0;
}
void kmp(string T,string P,int x){
    int len=T.size()-1,m=P.size()-1;
    for(int i=1,j=0;i<=len;i++){
        while(j>0&&P[j+1]!=T[i])j=nxt[x][j];
        if(P[j+1]==T[i])j++;
        if(j==m){
            if(check(i-m+1,1,x))ans++;
            j=nxt[x][j];
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        a[i]=' '+a[i];
        b[i]=' '+b[i];
        getnxt(a[i],i);
    }
    while(q--){
        cin>>t>>p;
        ans=0;
        t=' '+t;p=' '+p;
        for(int i=1;i<=n;i++){
            kmp(t,a[i],i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
