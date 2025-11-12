#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int read(){
    char t=getchar();
    while(t!='-'&&(t<'0'||t>'9'))t=getchar();
    int x=0,f=1;
    if(t=='-')f=-1,t=getchar();
    while('0'<=t&&t<='9')x=x*10+t-48,t=getchar();
    return x*f;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return ;
}
int dp[N][3];
int n,ma=INT_MIN;
int a[N*3];
void dfs(int x,int d[],int ans){
    if(x>n){
        ma=max(ma,ans);
        return ;
    }
    for(int i=0;i<=2;i++){
        if(((d[i]+1)<<1)<=n){
            d[i]++;
            dfs(x+1,d,ans+a[x+i*n]);
            d[i]--;
        }
    }
}
struct node{
    int id,i,k;
    bool operator<(const node a)const{
        return k<a.k;
    }
};
priority_queue<node>q;
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--){
        ma=INT_MIN;
        n=read();
        for(int i=1;i<=n;i++)a[i]=read(),a[i+n]=read(),a[i+n+n]=read();
        int d[3]={0,0,0};
        if(n<=15)
            dfs(1,d,0);
        else{
            while(!q.empty())q.pop();
            for(int i=1;i<=n;i++){
                q.push({i,0,a[i]});q.push({i,1,a[i+n]});q.push({i,2,a[i+n+n]});
            }
            int s=0;ma=0;map<int,bool>f;
            while(!q.empty()&&s<n){
                node top=q.top();q.pop();
                if(!f[top.i]&&2*(d[top.id]+1)<=n){
                    ma+=top.k;d[top.id]++;f[top.i]=1;
                }
            }
        }
        write(ma);putchar('\n');
    }
    return 0;
}
