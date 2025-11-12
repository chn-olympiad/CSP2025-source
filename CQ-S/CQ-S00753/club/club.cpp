#include<bits/stdc++.h>
using namespace std;
namespace YSJ{
    int T,n,tot,sum;
    bool f[100005];
    struct node{
        int d,x,num;
    }a[300005];
    bool cmp(node u,node v){
        return u.num>v.num;
    }
    int ff[35][4];
    int tmp[35];
    void js(){
        int summ=0;
        for(int i=1;i<=n;i++){
            summ+=ff[i][tmp[i]];
        }
        sum=max(sum,summ);
    }
    void dfs(int idx,int a,int b,int c){
        if(idx>n){
            js();
        }
        if(a<n/2){
            tmp[idx]=1;
            dfs(idx+1,a+1,b,c);
            tmp[idx]=0;
        }
        if(b<n/2){
            tmp[idx]=2;
            dfs(idx+1,a,b+1,c);
            tmp[idx]=0;
        }
        if(c<n/2){
            tmp[idx]=3;
            dfs(idx+1,a,b,c+1);
            tmp[idx]=0;
        }
    }
    void solve(){
        cin>>n;
        tot=0;sum=0;
        memset(f,0,sizeof(f));
        memset(ff,0,sizeof(ff));
        for(int i=1;i<=n;i++){
            int a1,a2,a3;
            cin>>a1>>a2>>a3;
            if(n<=10){
                ff[i][1]=a1;
                ff[i][2]=a2;
                ff[i][3]=a3;
            }
            a[++tot]={1,i,a1};
            a[++tot]={2,i,a2};
            a[++tot]={3,i,a3};
        }
        if(n<=10){
            dfs(1,0,0,0);
            cout<<sum<<'\n';
            return;
        }
        sort(a+1,a+tot+1,cmp);
        int d[5]={0,0,0,0};
        for(int i=1;i<=tot;i++){
            if(f[a[i].x])continue;
            if(d[a[i].d]>=(n/2))continue;
            d[a[i].d]++;
// cerr<<a[i].x<<' '<<a[i].d<<' '<<a[i].num<<'\n';
            sum+=a[i].num;
            f[a[i].x]=1;
        }
// cerr<<"-------------\n";
        cout<<sum<<'\n';
    }
    int main(){
        cin>>T;
        while(T--)solve();
        return 0;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    return YSJ::main();
}