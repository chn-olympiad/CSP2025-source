#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[100005][3],k,maxans;

void dfs(int num,int x,int y,int z){
    if(num==n+1){
        maxans=max(maxans,ans);
        return;
    }
    for(int i=0;i<=2;i++){
        ans+=a[num][i];
        if(i==0){
            if(x==n/2){
                ans-=a[num][i];
                continue;
            }
            else{
                dfs(num+1,x+1,y,z);
                ans-=a[num][i];
            }
        }
        if(i==1){
            if(y==n/2){
                ans-=a[num][i];
                continue;
            }
            else{
                dfs(num+1,x,y+1,z);
                ans-=a[num][i];
            }
        }
        if(i==2){
            if(z==n/2){
                ans-=a[num][i];
                continue;
            }
            else{
                dfs(num+1,x,y,z+1);
                ans-=a[num][i];
            }
        }
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        maxans=0;
        cin>>n;
        ans=0;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
        dfs(1,0,0,0);
        cout<<maxans<<endl;
    }
    return 0;
}
