#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int N = 1e4+5,M = 5e6+5;
int C[N],n,m,k,ans;
//set:
int f[N];
int find(int x){return (f[x]==x?x:f[x] = find(f[x]));}
//kk:
struct node{int u,v,w,m;} ns[M];
int kidx;
bool cmp(node x,node y){return x.w<y.w;}
void kk(){
    sort(ns,ns+kidx,cmp);
    for(int i = 0;i <= kidx;i++){
        int t1 = find(ns[i].v);
        int t2 = find(ns[i].u);
        if(t1!=t2){
            f[t1] = t2;
            ans += ns[i].w;
            ans += C[ns[i].m];
            //cout<<ns[i].v<<" "<<ns[i].u<<" "<<ns[i].w<<endl;
        }
    }
    /*
    for(int i = 0;i < kidx;i++){
        cout<<ns[i].u<<" "<<ns[i].v<<" "<<ns[i].w<<endl;
    }
    */
}
void add(int a,int b,int c,int m){
    ns[kidx].u = a,ns[kidx].v = b;ns[kidx].w = c;ns[kidx].m = m;
    kidx++;
}
/////
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i = 1;i < N;i++){f[i] = i;}
    for(int i = 10001;i <= 10050;i++){f[i] = 1;}
    for(int i = 1;i <= m;i++){
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        add(a,b,c,0);
    }
    for(int i = 1;i <= k;i++){
        scanf("%lld",&C[i]);
        for(int j = 1;j <= n;j++){
            int c;
            scanf("%lld",&c);
            add(i+10000,j,c,i);
        }
    }
    kk();
    printf("%lld",ans);
    return 0;
}