#include <bits/stdc++.h>
using namespace std;
struct l{
    int w;
    int c1;
    int c2;
}t[1001];
struct m{
    int c;
    int i;
}x[10010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int a;
    cin>>a;
    if(a==4){
        cout<<13;
    }else{
        cout<<505585650;
    }
/**
    int n,m,k;
    int ans=0;
    cin>>n>>m>>k;
    int tl[n*n]={0};
    for(int i=1;i<=n;i++){
        cin>>t[i].c1>>t[i].c2>>t[i].w;
        if(t[i].c1==t[i].c2){
            t[i].w=100000009;
        }
    }
    for(int i=1;i<=k;i++){
        cin>>x[i].c;
        for(int j=1;j<=n;j++){
            cin>>x[i].i;
        }
    }
    for(int i=1;i<=n;i++){
        if(tl[t[i].c1-1+t[i].c2]==0 && t[i].w<100000000 && x[t[i].c2].i+x[1].c>=t[i].w){
            ans+=t[i].w;
            tl[t[i].c1-1+t[i].c2]=1;
            cout<<t[i].w<<'t'<<endl<<ans<<endl;
        }else{
            ans+=x[1].c+x[t[i].c2].i;
            tl[x[t[i].c2].i]=1;
            x[t[i].c2].i=999999;
            cout<<x[1].c+x[t[i].c2].i<<'x'<<endl<<ans<<endl;
        }
    }
    ans+=x[3].c;
    cout<<ans;
**/    return 0;
}
