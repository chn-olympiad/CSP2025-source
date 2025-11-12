#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100;
int n;
int a[N];
int ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2){
            ans=1;
        }
    }
    cout<<ans;
    return 0;
}
