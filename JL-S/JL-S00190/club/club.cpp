#include<bits/stdc++.h>
using namespace std;
int sum[2],s[100005][5];
int f[5];
void dfs(int k,int m,int n){
    if(k>n){
        sum[0]=m;
        sort(sum,sum+2);
        return;
    }
    for(int i=1;i<=3;i++){
        if(f[i]<n/2){
            f[i]++;
            dfs(k+1,m+s[k][i],n);
            f[i]--;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i][1]>>s[i][2]>>s[i][3];
        }
        dfs(1,0,n);
        cout<<sum[1]<<endl;
        sum[1]=0;
        sum[0]=0;
    }
    return 0;
}
