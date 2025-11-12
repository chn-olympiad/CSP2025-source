#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][4];
int ans;

void dfs(int k,int x,int y,int z,int sum){
    if(k>n){
        ans=max(ans,sum);
        return ;
    }
    if(x+1<=n/2){
        dfs(k+1,x+1,y,z,sum+a[k][1]);
    }
    if(y+1<=n/2){
        dfs(k+1,x,y+1,z,sum+a[k][2]);
    }
    if(z+1<=n/2){
        dfs(k+1,x,y,z+1,sum+a[k][3]);
    }
    return ;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        bool flag=true;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0||a[i][3]!=0){
                flag=false;
            }
        }
        if(flag){
            priority_queue<int>q;
            for(int i=1;i<=n;i++){
                q.push(a[i][1]);
            }
            for(int i=1;i<=n/2;i++){
                ans+=q.top();
                q.pop();
            }
        }
        else{
            dfs(1,0,0,0,0);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
