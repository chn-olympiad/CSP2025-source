#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int t[N],p[N],p1[N],p2[N],p3[N];
int ans,n,T;
bool fa=1,fb=1;
struct node{
    int a,b,c;
}a[N];
bool vis[N];
void dfs(int id,int sum,int sa,int sb,int sc,int now){
    if(id==n+1){
        if(sum>ans){
            ans=sum;
            for(int i=1;i<=n;i++) p[i]=t[i];
        }
        return ;
    }
    if(sa<n/2){
        t[now]=1;
        dfs(id+1,sum+a[id].a,sa+1,sb,sc,now+1);
    }
    if(sb<n/2){
        t[now]=2;
        dfs(id+1,sum+a[id].b,sa,sb+1,sc,now+1);
    }
    if(sc<n/2){
        t[now]=3;
        dfs(id+1,sum+a[id].c,sa,sb,sc+1,now+1);
    }
    return ;
}
bool cmp1(node x,node y){
    return x.a>y.a;
}
bool cmp2(int x,int y){
    return a[x].a>a[y].a;
}
bool cmp3(int x,int y){
    return a[x].b>a[y].b;
}
bool cmp4(int x,int y){
    return a[x].c>a[y].c;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        fa=fb=1;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            if(a[i].a==0||a[i].b==0) fb=0;
            if(a[i].b!=0) fa=0;
            if(a[i].c!=0){
                fa=0;
                fb=0;
            }
        }
        ans=0;
        if(fa){
            int h2n=n/2;
            sort(a+1,a+1+n,cmp1);
            for(int i=1;i<=h2n;i++) ans+=a[i].a;
            cout<<ans<<endl;
            continue;
        }
        if(fb){
            int n1=0,n2=0,tot=0;
            for(int i=1;i<=n;i++){
                if(a[i].a>a[i].b){
                    n1++;
                    t[n1]=i;
                }
                else{
                    n2++;
                    p[n2]=i;
                }
            }
            sort(t+1,t+1+n1,cmp2);
            sort(p+1,p+1+n2,cmp3);
            int h2n=n/2;
            if(n1<n/2){
                for(int i=n2;i>=h2n;i--){
                    n1++;
                    t[n1]=p[i];
                }
            }
            if(n2<n/2){
                for(int i=n1;i>=h2n;i--){
                    n2++;
                    p[n2]=t[i];
                }
            }
            for(int i=1;i<=h2n;i++){
                ans+=a[t[i]].a;
//                cout<<t[i]<<" ";
            }
//            cout<<endl;
            for(int i=1;i<=h2n;i++){
                ans+=a[p[i]].b;
//                cout<<p[i]<<" ";
            }
//            cout<<endl;
            cout<<ans<<endl;
            continue;
        }
        if(n<=17){
            dfs(1,0,0,0,0,1);
            cout<<ans<<endl;
            continue;
        }
        memset(vis,0,sizeof(vis));
        int tot=0,sa=n/2,sb=n/2,sc=n/2;
        while(tot<n){
            int pa=0,pb=0,pc=0;
            for(int i=1;i<=n;i++){
                if(vis[i]) continue;
                int maxn=-1;
                if(sa!=0) maxn=max(maxn,a[i].a);
                if(sb!=0) maxn=max(maxn,a[i].b);
                if(sc!=0) maxn=max(maxn,a[i].c);
                if(a[i].a==maxn){
                    pa++;
                    p1[pa]=i;
                }
                if(a[i].b==maxn){
                    pb++;
                    p2[pb]=i;
                }
                if(a[i].c==maxn){
                    pc++;
                    p3[pc]=i;
                }
            }
            sort(p1+1,p1+1+pa,cmp2);
            sort(p2+1,p2+1+pb,cmp3);
            sort(p3+1,p3+1+pc,cmp4);
            for(int i=1;i<=pa&&sa>0;i++){
                if(vis[p1[i]]) continue;
                ans+=a[p1[i]].a;
                vis[p1[i]]=1;
                sa--;
                tot++;
            }
            for(int i=1;i<=pb&&sb>0;i++){
                if(vis[p2[i]]) continue;
                ans+=a[p2[i]].b;
                vis[p2[i]]=1;
                sb--;
                tot++;
            }
            for(int i=1;i<=pc&&sc>0;i++){
                if(vis[p3[i]]) continue;
                ans+=a[p3[i]].c;
                vis[p3[i]]=1;
                sc--;
                tot++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
