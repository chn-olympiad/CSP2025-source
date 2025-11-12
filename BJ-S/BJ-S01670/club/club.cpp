#include<bits/stdc++.h>
using namespace std;
int T,n,box[30],maxans;
struct node{
    int a,b,c;
}t[100006];
bool cmp(node x,node y){
    return x.a>y.a;
}
void dfs(int cur){
    if(cur>n){
        int r1=0,r2=0,r3=0,ans=0;
        for(int i=1;i<=n;i++){
            if(box[i]==1){
                ans+=t[i].a;
                r1++;
            }
            if(box[i]==2){
                ans+=t[i].b;
                r2++;
            }
            if(box[i]==3){
                ans+=t[i].c;
                r3++;
            }
        }
        if(r1<=n/2&&r2<=n/2&&r3<=n/2){
            maxans=max(maxans,ans);
        }
        return ;
    }
    int k1=0,k2=0,k3=0;
    for(int i=1;i<=3;i++){
        if(i==1) k1++;
        if(i==2) k2++;
        if(i==3) k3++;
        if(k1>(n/2)||k2>(n/2)||k3>(n/2)) return ;
        box[cur]=i;
        dfs(cur+1);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        int flag1=1,flag2=1;
        for(int i=1;i<=n;i++){
            cin>>t[i].a>>t[i].b>>t[i].c;
            if(t[i].c==0&&t[i].b!=0) flag1=0;
            if(t[i].b!=0&&t[i].c!=0) flag1=flag2=0;
        }
        if(flag1){
            sort(t+1,t+n+1,cmp);
            int ans=0;
            for(int i=1;i<=n/2;i++) ans+=t[i].a;
            cout<<ans;
        }else if(n<=30){
            dfs(1);
            cout<<maxans;
        }
    }
    return 0;
}
