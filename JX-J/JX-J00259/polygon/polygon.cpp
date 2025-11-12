#include<bits/stdc++.h>
using namespace std;
int n;
int a[10000];
long long ans;
void dfs(int s,int num,int da,int d){
    if(s>da*2 && d>=3 && s!=0 &&  num!=0 && da!=0){
        ans++;
    }
    if(d>=n){
        return;
    }
    for(int i=num+1;i<=n;i++){
        if(a[i]>=da){
            da=a[i];
        }
        d++;
        dfs(a[i]+s,i,da,d);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","W",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0,0,0,0);
    cout<<ans;
    return 0;
}
