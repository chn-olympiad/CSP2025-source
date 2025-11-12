#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=200+5;
struct Node{
    int x,y,z;
}a[N];
long long ans;
int n;
void DFS(int step,int u,int v,int w,long long res){
    if (step>n){
        ans=max(ans,res);
        return ;
    }
    if (u+1<=n/2) DFS(step+1,u+1,v,w,res+a[step].x);
    if (v+1<=n/2) DFS(step+1,u,v+1,w,res+a[step].y);
    if (w+1<=n/2) DFS(step+1,u,v,w+1,res+a[step].z);

}
bool cmp1(Node A,Node B){
    return A.x > B.x;
}
void MAIN(){
    bool flaga=true,flagb=true,flagc=true;
    ans=0;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
        if (a[i].y!=0 || a[i].z!=0) flaga=false;
    }
    if (n<=30){
        DFS(1,0,0,0,0);
        cout<<ans<<endl;
    }
    else if (flaga){
        sort(a+1,a+n+1,cmp1);
        for (int i=1;i<=n/2;i++) ans+=a[i].x;
        cout<<ans<<endl;
    }

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for (int i=1;i<=t;i++) MAIN();
    return 0;
}
