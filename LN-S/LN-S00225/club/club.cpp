#include<bits/stdc++.h>
using namespace std;
int T,n,ans,oi[100005];
struct node{
    int a;
    int b;
    int c;
    int d;
    int e;
}f[100005];
bool cmp(node x,node y){
    if(x.e==y.e)return x.d>y.d;
    else return x.e<y.e;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int oio=1;oio<=T;oio++){
        int jl[10],ans=0;
        memset(jl,0,sizeof(jl));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>f[i].a>>f[i].b>>f[i].c;
            int oo[10];
            oo[1]=f[i].a,oo[2]=f[i].b,oo[3]=f[i].c;
            sort(oo+1,oo+4);
            f[i].d=oo[3]-oo[2];
            if(f[i].a>=f[i].b&&f[i].a>=f[i].c)f[i].e=1;
            else if(f[i].b>=f[i].a&&f[i].b>=f[i].c)f[i].e=2;
            else if(f[i].c>=f[i].b&&f[i].c>=f[i].a)f[i].e=3;
        }
        sort(f+1,f+n+1,cmp);
        for(int i=1;i<=n;i++){
            jl[f[i].e]++;
            if(jl[f[i].e]>n/2){
                int jl=f[i].a+f[i].b+f[i].c-min(f[i].a,min(f[i].b,f[i].c))-max(f[i].a,max(f[i].b,f[i].c));
                ans+=jl;
            }
            else ans+=max(f[i].a,max(f[i].b,f[i].c));
        }
        oi[oio]=ans;
    }
    for(int i=1;i<=T;i++)
    cout<<oi[i]<<endl;
}
