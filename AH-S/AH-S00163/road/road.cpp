#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
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
int n,m,k;
struct edge{int u,v,w;};vector<edge>e;
int fa[N];
int fi(int x){
    return fa[x]=fa[x]==x?x:fi(fa[x]);
}
void un(int x,int y){
    fa[fi(x)]=fi(y);
}
void in(int n){
    for(int i=1;i<=n;i++)fa[i]=i;
}
struct city{
    int x;vector<int>a;
};
vector<city>c;
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int kru(vector<edge>e,int w,int k){
    sort(e.begin(),e.end(),cmp);
    in(n+k);
    int ans=w,s=1;
    for(int i=0;i<e.size();i++){
        if(s==n+k)break;
        if(fi(e[i].u)!=fi(e[i].v)){
            un(e[i].u,e[i].v);
            ans+=e[i].w;s++;

            //write(e[i].u);putchar(' ');write(e[i].v);putchar(' ');write(e[i].w);putchar('\n');
        }
    }
    return ans;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();//int llll=0;
    for(int i=0;i<m;i++){
        int u=read(),v=read(),w=read();//llll++;
        e.push_back({u,v,w});
    }
    for(int i=0;i<k;i++){
        int p=read();vector<int>t;
        for(int i=0;i<n;i++){
            t.push_back(read());//llll++;
        }
        c.push_back({p,t});
    }
    int d_min=kru(e,0,0),g=0,k=0;
    //write(d_min);putchar('\n');
    for(int i=0;i<k;i++){
        vector<edge>o;o=e;
        for(int j=0;j<c[i].a.size();j++){
            o.push_back({i+n+1,j+1,c[i].a[j]});
        }
        int hh=kru(o,g+c[i].x,k+1);
        if(hh<d_min){
            g+=c[i].x;k++;
            d_min=hh;
            e=o;
        }
        //write(hh);putchar('\n');
    }
    write(d_min);
    return 0;
}
