#include<iostream>
#include<algorithm>
#define mod 998244353
using namespace std;
int a[5000];
int ans;
void dfs(int n,int sum,int p,int cnt){
    if(n==-1){
        if(cnt>2)ans+=sum>p*2;
        return;
    }
    dfs(n-1,sum,p,cnt);
    dfs(n-1,sum+a[n],p==-1?a[n]:p,cnt+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    dfs(n-1,0,-1,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}