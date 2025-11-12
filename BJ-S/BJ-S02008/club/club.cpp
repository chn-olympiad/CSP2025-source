#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010];
int n,maxn=-1;
void dfs(int id,int sumall,int numa,int numb,int numc){
    if(id==n+1){
        if(numa*2>n||numb*2>n||numc*2>n)return;
        maxn=max(maxn,sumall);
        return;
    }
    dfs(id+1,sumall+a[id],numa+1,numb,numc);
    dfs(id+1,sumall+b[id],numa,numb+1,numc);
    dfs(id+1,sumall+c[id],numa,numb,numc+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int sssum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(c[i]!=0||b[i]!=0)sssum=1;
            if(c[i]!=0)sssum=2;
        }
        if(sssum==0){
            int ans=0;
            sort(a+1,a+n+1);
            for(int i=n;i>=n/2+1;i--){
                ans+=a[i];
            }
            cout<<ans<<endl;
            break;
        }
        else{
            dfs(1,0,0,0,0);
            cout<<maxn<<endl;
            maxn=-1;
        }
    }
    return 0;
}
