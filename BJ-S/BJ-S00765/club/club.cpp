#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Node{
    long long a,b,c;
};
struct Node1{
    int id;
    long long num;
};
Node t[100005];
int n;
long long ans=0;
void dfs(int k,long long cnta,long long cntb,long long cntc,int c1,int c2,int c3){
    if(k>=n+1){
        ans=max(ans,cnta+cntb+cntc);
        return ;
    }
    if(c1<n/2){
        dfs(k+1,cnta+t[k].a,cntb,cntc,c1+1,c2,c3);
    }
    if(c2<n/2){
        dfs(k+1,cnta,cntb+t[k].b,cntc,c1,c2+1,c3);
    }
    if(c3<n/2){
        dfs(k+1,cnta,cntb,cntc+t[k].c,c1,c2,c3+1);
    }
}
bool cmd1(Node x,Node y){
    if(x.a>=y.a){
        return true;
    }else{
        return false;
    }
}
bool cmd2(Node1 x,Node1 y){
    if(x.num>=y.num){
        return true;
    }else{
        return false;
    }
}
Node1 vis[1000005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    bool flag1=true,flag2=true;
    for(int _=1;_<=T;_++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>t[i].a>>t[i].b>>t[i].c;
            if(t[i].b==0||t[i].c==0){
                flag1=false;
            }else if(t[i].c==0){
                flag2=false;
            }
        }
        if(n<15){
            dfs(1,0,0,0,0,0,0);
            cout<<ans<<endl;
        }else if(flag1){
            sort(t+1,t+n+1,cmd1);
            for(int i=1;i<=n/2;i++){
                ans+=t[i].a;
            }
            cout<<ans<<endl;
        }else if(flag2){
            ans=0;
            for(int i=1;i<=n;i++){
                ans+=t[i].a;
            }
            for(int i=1;i<=n;i++){
                vis[i].id=i;
                vis[i].num=ans-t[i].a+t[i].b;
            }
            sort(vis+1,vis+n+1,cmd2);
            for(int i=1;i<=n/2;i++){
                ans=ans-t[vis[i].id].a+t[vis[i].id].b;
            }
            cout<<ans<<endl;
        }
        for(int i=1;i<=n;i++){
            t[i].a=t[i].b=t[i].c=0;
        }
        n=0;
        ans=0;
    }
    return 0;
}

