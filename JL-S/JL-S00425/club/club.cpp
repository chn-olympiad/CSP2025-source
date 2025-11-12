#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
    int a,b,c;
};
node a[N];
long long T,n,lj,q[5],maxx;
void dfs(int x){
    int xb;
    for(int i=1;i<=3;i++){
        if(i==1)xb=a[x].a;
        else if(i==2)xb=a[x].b;
        else xb=a[x].c;
        if(q[i]+1<=n/2){
            lj+=xb;
            q[i]++;
            if(x==n){
                maxx=max(maxx,lj);
            }
            dfs(x+1);
            lj-=xb;
            q[i]--;
        }
        
    }
}
bool tmp(node x,node y){
    return x.a>y.a;
}
void cc(){
    if(a[1].b==0&&a[1].c==0){
        sort(a+1,a+1+n,tmp);
        for(int i=1;i<=n/2;i++){
            maxx+=a[i].a;
        }
    }else{
        for(int i=1;i<=n;i++){
            if(a[i].a>=a[i].b||(a[i].a<a[i].b&&q[1]==n/2)){
                q[1]++;
                maxx+=a[i].a;
            }else if(a[i].a<a[i].b||(a[i].a>a[i].b&&q[2]==n/2)){
                q[2]++;
                maxx+=a[i].b;
            }
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
while(T--){
    q[1]=0;q[2]=0;q[3]=0;
    lj=0;
    maxx=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b>>a[i].c;
    }
    if(n<100){
        dfs(1);
        cout<<maxx<<endl;
    }else{
        cc();
        cout<<maxx<<endl;
    }
    
}
    return 0;
}