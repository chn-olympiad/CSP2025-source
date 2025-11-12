#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int MAXN=1e4+5,MAXK=20,MAXM=2e6+5;
int n,m,k,cnt,f[MAXN<<1],c[MAXN],a[MAXK][MAXN];
struct node{
    int x,y,z;
    bool operator<(const node& b)const{
        return z<b.z;
    }
}e[MAXM];

int find(int x){
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
void merge(int x,int y){
    f[find(x)]=find(y);
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>e[i].x>>e[i].y>>e[i].z;
    cnt=m;
    bool flag=true;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i])flag=false;
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    if(k==0){
        sort(e+1,e+cnt+1);
        int ans=0,res=0;
        for(int i=1;i<=cnt;i++)
            if(find(e[i].x)!=find(e[i].y)){
                merge(e[i].x,e[i].y);
                ans+=e[i].z;
                res++;
                if(res==n-1)break;
            }
        cout<<ans<<endl;
    }
    return 0;
}