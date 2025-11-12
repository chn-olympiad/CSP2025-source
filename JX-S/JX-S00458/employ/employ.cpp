#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,c[505],p[505],ans;
bool f[505];
string s;
void dfs(int k){
    if(k>n){
        int r=0;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='0'||r>=p[i]) r++;
        }
        if(r+m<=n) ans++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!f[i]){
            f[i]=true;
            p[k]=c[i];
            dfs(k+1);
            f[i]=false;
        }
    }
}
void solve(){
    scanf("%d%d",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    dfs(1);
    printf("%d\n",ans);
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int T=1;//scanf("%d",&T);
    while(T--) solve();
    return 0;
}
//The code only passed Example 1.
//NEVER GONNA GIVE YOU UP!!!
//freopen("employ,in",r,stdin);
//freopen("employ.ouy","w",stdout);
//This is my last CSP, so I want to surprise the person who is seeing this code.
//1145141919810 137891 (I still don't know what's this.)
//orz qhx xzy lyx pce sto %%%
//See my T2 code please!
//Luogu Qiu101029, uid: ...(I forgot...)
/*
    A     FFFFFFF   OOO
   A A    F        O   O
  AAAAA   FFFFFFF O     O
 A     A  F        O   O
A       A F         OOO      (It is so ugly...)
*/
//A fun fact: Every code is larger than 1000 bytes.
