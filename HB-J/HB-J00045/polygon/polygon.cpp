#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[5005]={0},n,ans=0;
bool flag=true;
bool cmp(int x,int y){
    return x<y;
}
void solve(int i,int num){
    if(i>n)
        return;
    if(i>=3&&num>a[i])
        ans++;
    solve(i+1,num);
    solve(i+1,num+a[i]);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)
            flag=false;
    }
    if(flag){
        cout<<(n*(n-1)*(n-2)/6);
        return 0;
    }
    if(n==3){
        if((2*max(a[1],max(a[2],a[3])))<(a[1]+a[2]+a[3]))
            cout<<"1";
        else
            cout<<"0";
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    solve(1,0);
    cout<<ans;
    return 0;
}
