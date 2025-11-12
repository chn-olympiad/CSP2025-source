#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n,a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;j++){
                if(a[i]+a[j]+a[k]>max(a[i],a[j],a[k])*2)ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}