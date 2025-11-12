#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100002][5];
int c[100002];
int ans;
void dfs(int x){
    if(x>n){
        int sum=0;
        int cnt1=0;
        int cnt2=0;
        int cnt3=0;
        for(int i=1;i<=n;i++){
            if(c[i]==1){
                cnt1++;
                sum+=a[i][1];
            }else if(c[i]==2){
                cnt2++;
                sum+=a[i][2];
            }else{
                cnt3++;
                sum+=a[i][3];
            }
        }
        if(cnt1<=n/2 && cnt2<=n/2 && cnt3<=n/2){
            ans=max(ans,sum);
        }
        return;
    }
    c[x]=1;
    dfs(x+1);
    c[x]=2;
    dfs(x+1);
    c[x]=3;
    dfs(x+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        dfs(1);
        cout<<ans<<"\n";
    }
    return 0;
}
