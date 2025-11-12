#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
struct node{
    int id,a,b,c,hope[3];
}a[100005],b[100005];
struct N{
    int id,v;
};
bool cmp(node x,node y){
    if(x.hope[0]!=y.hope[0])return x.hope[0]>y.hope[0];
    if(x.hope[1]!=y.hope[1])return x.hope[1]>y.hope[1];
    return x.hope[2]>y.hope[2];
}
int cnt[5];
vector<N> q[4],g[4];
void put(int id,int type,int x){
    int l=1,r=q[type].size()-1;
    while(l<r){
        int mid=(l+r+1)/2;
        if(q[type][mid].id>x){
            l=mid;
        }else{
            r=mid-1;
        }
    }l++;
    N tmp={id,x};
    for(l;l<q[type].size();l++){
        swap(tmp,q[type][l]);
        swap(tmp,q[type][l+1]);
    }q[type].push_back(tmp);
}int to(int id,int h){
    if(a[id].hope[h]==1)return a[id].a;
    if(a[id].hope[h]==2)return a[id].b;
    return a[id].c;
}bool check(int id,int type){
    int l=1,r=q[type].size()-1;
    while(l<r){
        int mid=(l+r+1)/2;
        if(q[type][mid].id>to(id,type)){
            l=mid;
        }else{
            r=mid-1;
        }
    }if(l<q[type].size()-1)return 1;
    else if(to(id,type)>q[type][q[type].size()-1].v)return 1;
    return 0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b>>a[i].c;
        a[i].id=i;
        if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
            if(a[i].b>=a[i].c)a[i].hope[0]=1,a[i].hope[1]=2,a[i].hope[2]=3;
            else a[i].hope[0]=1,a[i].hope[1]=3,a[i].hope[2]=2;
        }else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
            if(a[i].a>=a[i].c)a[i].hope[0]=2,a[i].hope[1]=1,a[i].hope[2]=3;
            else a[i].hope[0]=2,a[i].hope[1]=3,a[i].hope[2]=1;
        }else{
            if(a[i].b>=a[i].a)a[i].hope[0]=3,a[i].hope[1]=2,a[i].hope[2]=1;
            else a[i].hope[0]=3,a[i].hope[1]=1,a[i].hope[2]=2;
        }cnt[a[i].hope[0]]++;
    }sort(a+1,a+n+1,cmp);
    if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i].hope[0];
        }cout<<sum;
    }else{
        for(int i=1;i<=n/2;i++){
            q[a[i].hope[0]].push_back({a[i].id,to(a[i].id,a[i].hope[0])});
        }for(int i=n/2+1;i<=n;i++){
            if(cnt[a[i].hope[0]]<n/2)put(i,a[i].hope[0],to(i,0));
            if(cnt[a[i].hope[0]]>=n/2){
                if(check(i,a[i].hope[0])){
                    put(i,a[i].hope[0],to(i,0));
                    put(q[a[i].hope[0]][n/2].id,q[a[i].hope[0]][n/2].v,to(q[a[i].hope[0]][n/2].id,1));
                }else{
                    put(i,a[i].hope[1],to(i,1));
                }
            }
        }
    }long long abc=0;
    for(int i=1;i<=3;i++){
        for(int j=0;j<q[i].size();j++){
            abc+=q[i][j].v;
        }
    }cout<<abc<<endl;}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
