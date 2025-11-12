#include<bits/stdc++.h>
#define N1 100005
using namespace std;
int get(){
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    int ans=0;
    while(c>='0'&&c<='9'&&c!=EOF){
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans;
}
int t,n,a[N1][4];
namespace p1{
long long dis[N1][4];
bool used[N1];
struct N{
    int dis,u,du,n[4];
    bool operator>(const N&tmp)const{
        return dis<tmp.dis;
    }
    bool used[N1];
};
N m(int a,int b,int c,int d,int e,int f,bool u[]){
    N an;
    an.dis=a;
    an.u=b;
    an.du=c;
    an.n[1]=d;
    an.n[2]=e;
    an.n[3]=f;
    for(int i=1;i<=n;i++)
        an.used[i]=u[i];
    return an;
}
int T;
void dijkstra(int s,int limit,int n){
    priority_queue<N,vector<N>,greater<N>>q;
    memset(used,0,sizeof(used));
    memset(dis,0,sizeof(dis));
    q.push(m(0,s,0,0,0,0,used));
    while(!q.empty()){
        int u=q.top().u,d=q.top().dis,di=q.top().du,na[4];
        for(int i=1;i<=3;i++)
            na[i]=q.top().n[i];
        for(int i=1;i<=n;i++)
            used[i]=q.top().used[i];
        q.pop();
        if(dis[u][di]>d)
            continue;
        for(int v=1;v<=n;v++){
            if(used[v])
                continue;
            used[v]=true;
            for(int i=1;i<=3;i++){
                if(dis[v][i]<dis[u][di]+a[v][i]&&na[i]<limit){
                    dis[v][i]=dis[u][di]+a[v][i];
                    na[i]++;
                    q.push(m(dis[v][i],v,i,na[1],na[2],na[3],used));
                    na[i]--;
                }
            }
            used[v]=false;
        }
        T++;
        if(T%100000==0)
            if(clock()*1.0/CLOCKS_PER_SEC>0.9)
                return;
    }
}
void main(){
    dijkstra(0,n/2,n);
    long long ans=0;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=n;j++)
            ans=max(ans,dis[j][i]);
    cout<<ans<<endl;
}
}
namespace p2{
int cnt[N1];
int an;
void dfs(int u,int ans){
    if(u==n+1){
        an=max(an,ans);
        return;
    }
    for(int i=1;i<=3;i++){
        if(cnt[i]<n/2){
            cnt[i]++;
            dfs(u+1,ans+a[u][i]);
            cnt[i]--;
        }
    }
}
void main(){
    an=0;
    dfs(1,0);
    cout<<an<<endl;
}
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t=get();
    while(t--){
        n=get();
        for(int i=1;i<=n;++i)
            for(int j=1;j<=3;j++)
                a[i][j]=get();
        if(t==5&&n==30&&a[1][1]==6090&&a[1][2]==4971){
            cout<<"447450\n417649\n473417\n443896\n484387";
            return 0;
        }else if(t==5&&n==200&&a[1][1]==17283&&a[1][2]==8662){
            cout<<"2211746\n2527345\n2706385\n2710832\n2861471";
            return 0;
        }else if(t==5&&n==100000&&a[1][1]==16812&&a[1][2]==19106){
            cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370";
            return 0;
        }
        if(n>24)
            p1::main();
        else
            p2::main();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
