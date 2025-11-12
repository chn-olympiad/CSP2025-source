#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5009];
bool v[5009];
void num(int x,int maxn,int al){
    if(x>=3&&al>maxn*2){
        ans++;
    }
    for(int i=1;i<=n;i++){
        if(v[a[i]]==0){
            v[a[i]]=1;
            num(x+=1,max(maxn,a[i]),al+=a[i]);
            v[a[i]]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    v[a[1]]=1;
    num(1,a[1],a[1]);
    cout<<ans%998244353;
    return 0;
}
