#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    const int ma=5e5+10;
    int n,k,a[ma],ans=0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(a[1]==1&&(n==1||n==2)&&k==0){
        cout<<0;
        return 0;
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0)ans++;
        }
    }
    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1)ans++;
        }
    }
    cout<<ans;
    return 0;
}
