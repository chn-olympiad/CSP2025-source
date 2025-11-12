#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],f[30005],cnt;
bool flag[15];
long long ans;
struct Node{
    int x,y,z,id;
}e[300005],E[1000005];
bool cmp(Node a,Node b){
    return a.z<b.z;
}
int fa(int x){
    if(f[x]==x) return x;
    return f[x]=fa(f[x]);
}
void check(long long sum,int p){
    for(int j=1;j<=n+k;j++) f[j]=j;
    for(int j=1;j<=cnt;j++){
        if(flag[e[j].id]==1&&fa(e[j].x)!=fa(e[j].y)){
            f[fa(e[j].x)]=fa(e[j].y);
            sum+=e[j].z;
            p--;
            if(p==1) break;
        }
    }
    ans=min(ans,sum);
}
void dfs(int x){
    if(x>k){
        long long sum=0;
        int l=n;
        for(int i=1;i<=k;i++){
            if(flag[i]==1) sum+=c[i],l++;
        }
        check(sum,l);
        return;
    }
    dfs(x+1);
    flag[x]=1;
    dfs(x+1);
    flag[x]=0;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    flag[0]=1;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>E[i].x>>E[i].y>>E[i].z;
    }
    sort(E+1,E+m+1,cmp);
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        if(fa(E[i].x)!=fa(E[i].y)){
            f[fa(E[i].x)]=fa(E[i].y);
            ans+=E[i].z;
            e[++cnt]=E[i];
        }
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>e[++cnt].z;
            e[cnt].x=n+i;
            e[cnt].y=j;
            e[cnt].id=i;
        }
    }
    sort(e+1,e+cnt+1,cmp);
    dfs(1);
    cout<<ans;
    return 0;
}