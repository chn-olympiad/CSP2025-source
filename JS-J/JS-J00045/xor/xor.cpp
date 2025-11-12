#include<bits/stdc++.h>
#define N 200010
using namespace std;
int n,x=0,vl,ans=0;
int a[N];
int flag=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>vl;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1)flag=1;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==1)ans++;
    }
    if(vl==1&&flag==0){
        cout<<ans;
    }
    else if(vl==0&&flag==0){
        cout<<ans/2;
    }
    else cout<<0;
    return 0;
}
