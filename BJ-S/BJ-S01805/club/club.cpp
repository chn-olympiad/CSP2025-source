#include<iostream>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;
int n,m,nm,k;
int val[20];
int to[20][10010];
int fa[10010];
ll tot;
struct node{
    ll l,r,v;
};
bool cmp(node a,node b){
    return a.v<b.v;
}
node z[2000010];
node z1[2000010];
inline ll read(){
    ll ans=0;int x=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') x=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        ans=ans*10+ch-'0';
        ch=getchar();
    }
    return ans*x;
}
int nn;
int f(int x){
    if(fa[x]==x) return x;
    fa[x]=f(fa[x]);
    return fa[x];
}
ll kru(){
    sort(z+1,z+1+nm,cmp);
    for(int i=1;i<=n;i++) fa[i]=i;
    ll ans=0;
    int tot=0;
    for(int i=1;i<=nm;i++){
        int a=f(z[i].l);
        int b=f(z[i].r);
        if(a!=b){
            fa[a]=b;
            tot++;
            ans+=z[i].v;
        }
        if(tot==nn-1){
            break;
        }
    }
    return ans;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        z[i].l=read();
        z[i].r=read();
        z[i].v=read();
        z1[i].l=z[i].l;
        z1[i].r=z[i].r;
        z1[i].v=z[i].v;
    } nn=n;
    if(k==0){
        cout << kru();
        return 0;
    }
   
    else{
        for(int i=1;i<=k;i++){
            cin >> val[i];
            for(int j=1;j<=n;j++){
                cin >> to[i][j];
            }
        }
        tot=10000000000010;
        nm=m;
        for(int s=0;s<(1<<k);s++){
            ll sum=0;
            for(int i=0;i<k;i++){
                if((s>>i)&1){
                    nn++;
                    for(int j=1;j<=n;j++){
                        z[nm+j].l=j;
                        z[nm+j].r=n+i+1;
                        z[nm+j].v=to[i+1][j];
                    }
                    nm+=n;
                    sum+=val[i+1];
                }
            }
            //    cout << s << "\n";
            //   for(int i=1;i<=nm;i++){
                    //    cout << i << ' ' << z[i].l<< ' ' << z[i].r<< ' ' << z[i].v << "\n";
            // }
            //  cout << nm << "\n";
                //cout << tot << ' ' << sum+kru() << "\n";
            tot=min(tot,sum+kru());
            //cout << nn << "\n";
            for(int i=1;i<=m;i++){
                z[i].l=z1[i].l;
                z[i].r=z1[i].r;
                z[i].v=z1[i].v;
            }
            nm=m;
            nn=n;
        }
        cout << tot;
    }

}