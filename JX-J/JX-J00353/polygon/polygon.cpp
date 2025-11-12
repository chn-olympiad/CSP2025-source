#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5005;
int a[N],cnt=0,mx=INT_MIN,ans,n,len;
void dfs(int top,int s){
    if(top<=0){
        if(ans>mx*2){
            cnt++;
        }
        return ;
    }
    for(int i=s; i<=n-top+1; i++){
        ans+=a[i];
        bool flag=false;
        int t=mx;
        mx=max(a[i],mx);
        dfs(top-1,i+1);
        mx=t;
        ans-=a[i];
    }
}
int main(){
//    freopen("polygon.in","r",stdin);
//    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; ++i){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
        return 0;
    }else if(n==3){
        int sum=a[1]+a[2]+a[3],t=2*max(a[1],max(a[2],a[3]));
        if(sum>t){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    for(len=3; len<=n; len++){
        dfs(len,1);
    }
    cout<<cnt;
    return 0;
}
