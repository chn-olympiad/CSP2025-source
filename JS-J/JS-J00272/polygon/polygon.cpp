#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int num[505];
int n;
int a[505];
int ans;
void dfs(int i,int dep,int last,int cnt){
    if(dep>=3){
        if(cnt>last*2&&last==i-1){
            ans++;
            //cout<<i<<" "<<dep<<" "<<last<<" "<<cnt<<endl;
        }
        if(i==n)return;
        dfs(i+1,dep+1,i,cnt+a[i]);
        dfs(i+1,dep,last,cnt);
    }else{
        if(i==n)return;
        dfs(i+1,dep+1,i,cnt+a[i]);
        dfs(i+1,dep,last,cnt);
    }
    return;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    /*for(int i=0;i<n;i++){
        num[i][i]=a[i];
        for(int j=i+1;j<n;j++){
            num[i][j]=num[i][j-1]+a[j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<num[i][j]<<" ";
        }
        cout<<endl;
    }*/
    dfs(0,0,0,0);
    cout<<ans;
    return 0;
}
