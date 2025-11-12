#include <bits/stdc++.h>
using namespace std;
int a[200005][5],t,n,sum[5],ans[5],maxn;
void Dfs(int x){
    if(x>n){
        if(maxn<ans[1]+ans[2]+ans[3]){
            maxn=ans[1]+ans[2]+ans[3];
            return ;
        }
        return ;
    }
    for(int i=1;i<=3;i++){
        if(sum[i]<n/2){
            sum[i]++;
            ans[i]+=a[x][i];
            Dfs(x+1);
            sum[i]--;
            ans[i]-=a[x][i];
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j][1]>>a[j][2]>>a[j][3];
        }
        maxn=0;
        ans[1]=ans[2]=ans[3]=sum[1]=sum[2]=sum[3]=0;
        Dfs(1);
        cout<<maxn<<endl;
    }
    return 0;
}
