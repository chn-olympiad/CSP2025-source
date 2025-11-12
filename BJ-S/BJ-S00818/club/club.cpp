#include<bits/stdc++.h>
using namespace std;
int box[100005],n,ans,a[100005][5];;
void dfs(int x,int cnt1,int cnt2,int cnt3){
    if(cnt1>n/2||cnt2>n/2||cnt3>n/2){
        return;
    }
    if(x>n){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i][box[i]];
        }
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=3;i++){
        box[x]=i;
        if(i==1){
            dfs(x+1,cnt1+1,cnt2,cnt3);
        }else if(i==2){
            dfs(x+1,cnt1,cnt2+1,cnt3);
        }else{
            dfs(x+1,cnt1,cnt2,cnt3+1);
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        memset(a,0,sizeof(a));
        memset(box,0,sizeof(box));
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        dfs(1,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
