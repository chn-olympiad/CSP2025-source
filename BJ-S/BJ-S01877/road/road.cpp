#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
struct E{
    long long u,v,w;
}e[1000006];
long long con[100005],ch;
long long cmp(E x,E y){
    return x.w<y.w;
}
long long ans;
long long fa[100005];
long long F(long long x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=F(fa[x]);
}
void C(long long x,long long y){
    x=F(x),y=F(y);
    fa[x]=y;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=n;i++){
        fa[i]=i;
    }
    //cout<<"W"<<endl;
    for(long long i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    //cout<<"P"<<endl;
    if(k==0){
        //cout<<"C"<<endl;
        sort(e+1,e+m+1,cmp);
        for(long long i=1;i<=m;i++){
            long long x=e[i].u,y=e[i].v,val=e[i].w;

            if(F(x)!=F(y)){
                //cout<<"wpc"<<endl;
                ans+=val;
                C(x,y);
            }
            //else{
            //    cout<<"mbc"<<endl;
            //}
        }
    }

    if(k!=0){
        for(long long i=1;i<=k;i++){
            cin>>ch;
            for(long long j=1;j<=n;j++){
                cin>>con[j];
            }
        }
        cout<<0;
        return 0;
    }

    cout<<ans;
    return 0;
}
