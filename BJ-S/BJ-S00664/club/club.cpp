#include<bits/stdc++.h>
using namespace std;
int n,xuan[100005],ccnt[5],a[100005][5],ans=-1;
void dfs(int cur){
    if(cur>n){
        int myd=0;
        for(int i=1;i<=n;i++){
            ccnt[xuan[i]]++;
           // cout<<xuan[i]<<" ";
            myd+=a[i][xuan[i]];
        }
       // cout<<ccnt[1]<<" "<<ccnt[2]<<" "<<ccnt[3];
        if(ccnt[1]<=n/2&&ccnt[2]<=n/2&&ccnt[3]<=n/2){
            ans=max(myd,ans);//cout<<"ans:"<<ans;
        }//<<endl;
        ccnt[1]=0,ccnt[2]=0,ccnt[3]=0;
        return;
    }
    for(int i=1;i<=3;i++){
        xuan[cur]=i;
        dfs(cur+1);
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){

        cin>>n;
        ans=-1;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        dfs(1);
        cout<<ans<<endl;
    }

    return 0;
}
