#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x*=10,x+=(int)(ch-'0');
        ch=getchar();
    }
    return x*f;
}

const int N=510,mod=998244353;
int n,m,c[N];
char ch[N];

bool used[N];
int a[N];
int check(){
    int no=0,yes=0;
    for(int i=1;i<=n;i++){
        if(c[a[i]]>no &&ch[i]=='1')
            yes++;
        else no++;
    }
    return yes;
}
int ans=0;
void dfs(int x){
    if(x==n+1){
        if(check()>=m) ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]) {
        a[x]=i;
        used[i]=1;
        dfs(x+1);
        used[i]=0;
        }
    }
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();
    cin>>ch+1;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(n<=20){
        dfs(1);
        cout<<ans<<endl;
    }else {
        cout<<0;
    }
    return 0;
}   
