#include<bits/stdc++.h>
#define reg register
#define ll long long
#define mp make_pair
#define pi pair<int,int>
#define il inline
using namespace std;
il int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9')f=(ch=='-'?-1:f),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
    return x*f;
}
const int N=505;
int n,m,ans,a[N],p[N];
bool vis[N];
string s;
bool check(){
    int tot=0,cnt=0;
    for(reg int i=1;i<=n;i++){
        if(s[i-1]=='0')cnt++;
        else{
            if(cnt>=a[p[i]])cnt++;
            else tot++;
        }
    }
    return (tot>=m);
}
void dfs(int k){
    if(k>n){
        ans+=check();
        return;
    }
    for(reg int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=1;
        p[k]=i;
        dfs(k+1);
        p[k]=0;
        vis[i]=0;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    n=read(),m=read();
    cin>>s;
    for(reg int i=1;i<=n;i++)
        a[i]=read();
    if(n<=10){
        dfs(1);
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}

