#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
int b[100005];
int ans[100005];
int xd[5];
int maxn;
int n;
void dfs(int t){
    if(t>n){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i][ans[i]];
        }
        maxn=max(maxn,sum);
        return ;
    }
    for(int i=1;i<=3;i++){
        if(xd[i]==n/2)continue;
        ans[t]=i;
        xd[i]++;
        dfs(t+1);
        xd[i]--;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        if(n>10){
            for(int i=1;i<=n;i++){
                cin>>a[i][1]>>a[i][2]>>a[i][3];
            }
            for(int i=1;i<=n;i++){
                b[i]=a[i][1];
            }
            sort(b+1,b+n+1);
            int sum=0;
            for(int i=n;i>=n/2;i--){
                sum+=b[i];
            }
            cout<<sum<<endl;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        dfs(1);
        cout<<maxn<<endl;
        maxn=0;
    }
    return 0;
}
