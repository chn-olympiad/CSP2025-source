#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int arr[5005],ans=0,n;
void dfs(int a,int cnt,int maxa,int c){
    if(c>n)return;
    for(int i=a;i<=n;i++){

        if(c>=3&&cnt+arr[i]>2*max(maxa,arr[i]))ans++;
        ans%=Mod;
        dfs(i+1,cnt+arr[i],max(maxa,arr[i]),c+1);
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
    dfs(1,0,-1,1);
    cout<<ans;
    return 0;
}
