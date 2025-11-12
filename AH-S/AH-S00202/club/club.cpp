#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],flag23=true;
int dfs(int id,int cnt1,int cnt2,int cnt3,int sum){
    if(id==n+1){
        return sum;
    }
    int ans=0;
    if(cnt1+1<=n/2){
        ans=dfs(id+1,cnt1+1,cnt2,cnt3,sum+a[id][1]);
    }
    if(cnt2+1<=n/2){
        ans=max(ans,dfs(id+1,cnt1,cnt2+1,cnt3,sum+a[id][2]));
    }
    if(cnt3+1<=n/2){
        ans=max(ans,dfs(id+1,cnt1,cnt2,cnt3+1,sum+a[id][3]));
    }
    return ans;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0||a[i][3]!=0){
                flag23=false;
            }
        }
        if(n<=10) cout<<dfs(1,0,0,0,0)<<"\n";//1~4
        else if(flag23){//12
            int tmp[100005]={0};
            for(int i=1;i<=n;i++){
                tmp[i]=a[i][1];
            }
            sort(tmp+1,tmp+n+1);
            int ans=0;
            for(int i=n/2+1;i<=n;i++){
                ans+=tmp[i];
            }
            cout<<ans;
        }
    }
    return 0;
}
