#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int arr[100005][5];
int ma=0;
void dfs(int a,int b,int c,int sum,int step){
    
    if(step>n){
        ma=max(sum,ma);
        return;
    }
    for(int i=1;i<=3;i++){
        if(a>=n/2&&i==1)continue;
        if(b>=n/2&&i==2)continue;
        if(c>=n/2&&i==3)continue;
        if(i==1)dfs(a+1,b,c,sum+arr[step][i],step+1);
        if(i==2)dfs(a,b+1,c,sum+arr[step][i],step+1);
        if(i==3)dfs(a,b,c+1,sum+arr[step][i],step+1);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int ti=1;ti<=t;ti++){
        ma=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++)cin>>arr[i][j];
        }
        dfs(0,0,0,0,1);
        cout<<ma;
    }
}
