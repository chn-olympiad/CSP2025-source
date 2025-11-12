#include<bits/stdc++.h>
using namespace std;
int T;
int n,ans,res;
int a[100005][3];
int t[3];
int b[100005];
void dfs(int nd,int st){
    res+=a[nd][st];
    if(nd==n){
        ans=max(ans,res);
        res-=a[nd][st];
        return;
    }
    for(int i=0;i<3;i++){
        if(t[i]<n/2){
            t[i]++;
            dfs(nd+1,i);
            t[i]--;
        }
    }
    res-=a[nd][st];
    return;
}
void fn1(int st){
    for(int i=1;i<=n;i++){
        b[i]=a[i][st];
    }
    sort(b+1,b+1+n);
    int res=0;
    for(int i=1;i<=n/2;i++){
        res+=b[i];
    }
    cout<<res<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ans=0;
        int f[3]={1,1,1};
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
            f[0]=(f[0]==0?0:a[i][0]==0);
            f[1]=(f[1]==0?0:a[i][1]==0);
            f[2]=(f[2]==0?0:a[i][2]==0);
        }
        if(f[0]+f[1]+f[2]==3){
            cout<<"0\n";
            continue;
        }
        if(f[0]+f[1]+f[2]==2){
            if(f[0]==0)fn1(0);
            else if(f[1]==0)fn1(1);
            else fn1(2);
            continue;
        }
        for(int i=0;i<3;i++){
            t[i]++;
            dfs(1,i);
            t[i]--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
