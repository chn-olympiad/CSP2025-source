#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
};
node p[209];int n,f[209],cnt,k[3];
void dfs(int x,int s){
    if(x==n){
        cnt=max(cnt,s);
        return;
    }
    if(k[0]<n/2){
        k[0]++;
        dfs(x+1,s+p[x].a);
        k[0]--;
    }
    if(k[1]<n/2){
        k[1]++;
        dfs(x+1,s+p[x].b);
        k[1]--;
    }
    if(k[2]<n/2){
        k[2]++;
        dfs(x+1,s+p[x].c);
        k[2]--;
    }
}
bool cmp(node x,node y){
    if(x.a!=y.a){
        return x.a>y.a;
    }
    if(x.b!=y.b){
        return x.b>y.b;
    }
    return x.c>y.c;
}
int main(){
    int t;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>p[i].a>>p[i].b>>p[i].c;
        }
        sort(p,p+n,cmp);
        memset(k,0,sizeof k);
        cnt=0;
        dfs(0,0);
        cout<<cnt<<endl;
    }
    return 0;
}