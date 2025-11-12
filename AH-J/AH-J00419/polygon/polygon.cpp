#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 5005
#define Mod 998244353
using namespace std;
int n,a[N];
int dfs(int pos,int sum,int mx,int cnt){
    //cout<<pos<<path<<endl;
    if(pos>n){
        if(cnt<=2||sum<=2*mx) return 0;
        return 1;
    }
    return dfs(pos+1,sum+a[pos],max(mx,a[pos]),cnt+1)+dfs(pos+1,sum,mx,cnt);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<dfs(1,0,0,0);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
