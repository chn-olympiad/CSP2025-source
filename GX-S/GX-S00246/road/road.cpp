#include<bits/stdc++.h>
using namespace std;
long long fa[10086];
long long cz(long long x){
    if(x==fa[x]) return x;
    return fa[x]=cz(fa[x]);
}
void hb(long long a,long long b){
    a=cz(a);
    b=cz(b);
    if(a!=b){
        fa[b]=a;
    }
    return ;
}
struct abc{
    long long u;
    long long v;
    long long w;
};
bool cmp(abc a,abc b){
    return a.w<b.w;
}
int main(){
    ios::sync_with_stdio(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n;
    long long m;
    long long k;
    cin>>n>>m>>k;
    vector<abc> a;
    for(long long i=0;i<m;i++){
        long long u;
        long long v;
        long long w;
        cin>>u>>v>>w;
        a.push_back({u,v,w});
    }
 //   int c[k+1][n+1];
   // memset(c,0,sizeof(c));
    for(long long i=1;i<=n+5;i++){
        fa[i]=i;
    }
    for(long long i=1;i<=k;i++){
        long long cw;
        cin>>cw;
        long long c[n+1];
        memset(c,0,sizeof(c));
        for(long long i=1;i<=n;i++){
            cin>>c[i];
        //    cout<<c[i];
        }
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
              //  if()
         //       cout<<i<<"-"<<j<<" "<<cw+c[i]+c[j]<<"\n";
                a.push_back({i,j,cw+c[i]+c[j]});
            }
        }
    }

    sort(a.begin(),a.end(),cmp);
    long long b=0;
    long long q=0;
 //   cout<<a.size()<<"\n";
 /*   for(int i=0;i<=a.size();i++){
        cout<<a[i].u<<"-"<<a[i].v<<" "<<a[i].w<<"\n";
    }*/
    for(int i=0;i<=a.size();i++){
    //    cout<<a[i].u<<"-"<<a[i].v<<" "<<a[i].w<<"\n";
        //  cout<<123;
        if(b==n-1){
            cout<<q;
            break;
        }
        if(cz(a[i].u)!=cz(a[i].v)){
            hb(a[i].u,a[i].v);
   //         cout<<a[i].u<<"-"<<a[i].v<<" "<<a[i].w<<"\n";
       //     cout<<123;
            q=q+a[i].w;
          //  cout<<q;
            b++;
        }
        if(b==n-1){
            cout<<q;
            break;
        }
    }

    return 0;
}
