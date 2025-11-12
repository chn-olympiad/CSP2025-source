#include<bits/stdc++.h>
using namespace std;
const int md=998244353;
int n,a[5005],ans=0,emp[5005]={};
bool itin(int x,int y[],int si){
    for(int i=0;i<si;i++){
        if(x==y[i]){
            return 1;
        }
    }
    return 0;
}
void dfs(int sum,int mx,int m,int no[],int cnt,int first){
    if(sum>2*mx&&m>=3){
        ans++;
    }
    if(m>=n){
        return;
    }
    for(int i=first;i<=n;i++){
        if(itin(i,no,cnt)){
            continue;
        }
        no[cnt]=i;
        dfs(sum+a[i],max(mx,a[i]),m+1,no,cnt+1,i);
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,0,emp,0,1);
    cout<<ans%md;
    return 0;
}
