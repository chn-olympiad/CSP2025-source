#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxm=1e6+50;
const int maxn=1e4+50;
struct node{
    int u,v,da;
}edge[maxm],edge1[maxn],edge2[maxm];
bool cmp(node &a,node &b){
    return a.da<b.da;
}
vector<pair<int,int> > v[maxn];
int fa[maxn];

int find(int x){
    if(x==fa[x]) return x;
    else return fa[x]=find(fa[x]);
}
int arr[20][maxn],cost[20];
int n,m,k;
vector<int> qwq[20];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].da);
    }
    sort(edge+1,edge+1+m,cmp);
    for(int i=1;i<=n;i++) fa[i]=i;
    int ans=0,cnt=0;
    vector<int> res;
    int mx=0;
    for(int i=1;i<=m;i++){
        int a=find(edge[i].u),b=find(edge[i].v);
        if(a!=b){
            res.push_back(i);
            fa[a]=b;
            ans+=edge[i].da;
            cnt++,mx=max(mx,edge[i].da);
            edge1[cnt]=edge[i];
       //     fprintf(stderr,"%lld\n",ans);
        }
    }
   // fprintf(stderr,"%d\n",ans);
    for(int i=1;i<=k;i++){
        scanf("%lld",&cost[i]);
        for(int j=1;j<=n;j++){
            scanf("%lld",&arr[i][j]);
            if(arr[i][j]<=mx) qwq[i].push_back(j);
        }
    }
    for(int p=1;p<(1<<k);p++){
        int cnt_ed=0,cnt_pos=n;
        int sum=0;
        for(int j=0;j<k;j++){
            if(p&(1<<j)){
                for(int i:qwq[j+1]){
                    ++cnt_ed;
                    edge2[cnt_ed].u=n+j+1,edge2[cnt_ed].v=i,edge2[cnt_ed].da=arr[j+1][i];
                }
                sum+=cost[j+1];  
                cnt_pos++;              
            }
        }
     //   fprintf(stderr,"%d",sum);
        for(int i=1;i<=n+k;i++) fa[i]=i;
        sort(edge2+1,edge2+1+cnt_ed,cmp);
        int l=1;
        for(int i=1;i<n;i++){
            node res;
            if(l<cnt_ed&&edge1[i].da>edge2[l].da) res=edge2[l++],i--;
            else res=edge1[i];
            int a=find(res.u),b=find(res.v);
         //   fprintf(stderr,"%d %d %d\n",edge[i].u,edge[i].v,edge[i].da);
            if(a!=b){
                fa[a]=b,cnt_pos--;
                sum+=res.da;
                if(cnt_pos==1) break;
            }
        }
        if(sum<ans) ans=sum;
     //   fprintf(stderr,"%lld %lld\n",p,ans);
    }
    printf("%lld\n",ans);
    return 0;
}