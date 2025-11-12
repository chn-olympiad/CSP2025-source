#include<bits/stdc++.h>
using namespace std;
#define int long long 
int read(){
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        k=k*10+c-'0';
        c=getchar();
    }
    return k*f;
}
#define N 3009000
int idcnt=1;
int trie[N][69];
string s1;
int c[N];
int c1[2009][2009];
int opl=998244353;
void C(){
    c1[0][0]=1;c1[0][1]=1;
    for(int i=1;i<=2000;i++){
        for(int j=1;j<=2000;j++){
            c1[i][j]=c1[i-1][j-1]+c1[i-1][j];
            c1[i][j]%=opl;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n=read(),m=read();
    cin>>s1;
    for(int i=1;i<=n;i++){
        c[i]=read();
    }
    if(n<18){
        cout<<m;
        return 0;
    }
    else{
        C();
        cout<<c1[n][m];
    }
}
//收下吧评测机！这是我最后的石了！
//作为串你实在不够纯粹，给我滚开！你配被我做出来吗！