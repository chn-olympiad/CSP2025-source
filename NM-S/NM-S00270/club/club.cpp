#include<bits/stdc++.h>
using namespace std;
int n,t;
long long ans1,maxn;
struct node{
    int  x,y,z;
};
bool cmp1(node a,node b){
    return a.x>b.x;
}
node a[100010]={0};
void dfs1(int pos,int x1,int y1,int z1,long long sum){
    if(x1>(n/2)||y1>(n/2)||z1>(n/2)){
        return;
    }
    if(pos==n+1){
        maxn=max(maxn,sum);
        return;
    }
    dfs1(pos+1,x1+1,y1,z1,sum+a[pos].x);
    dfs1(pos+1,x1,y1+1,z1,sum+a[pos].y);
    dfs1(pos+1,x1,y1,z1+1,sum+a[pos].z);
    return;
}
void dfs2(int pos,int x1,int y1,long long sum){
    if(x1>(n/2)||y1>(n/2)){
        return;
    }
    if(pos==n+1){
        maxn=max(maxn,sum);
        return;
    }
    dfs2(pos+1,x1+1,y1,sum+a[pos].x);
    dfs2(pos+1,x1,y1+1,sum+a[pos].y);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        maxn=0;
        int flag=1,flag1=1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].y>0||a[i].z>0){
                flag=0;
            }
            if(a[i].z>0){
                flag1=0;
            }
        }
        if(flag){
            sort(a+1,a+n+1,cmp1);
            for(int i=1;i<=n/2;i++){
                ans1+=a[i].x;
            }
            cout<<ans1;
            continue;
        }
        else if(flag1){
            dfs2(1,0,0,0);
            cout<<maxn<<endl;
        }
        else{
            dfs1(1,0,0,0,0);
            cout<<maxn<<endl;
        }
    }
    return 0;
}


