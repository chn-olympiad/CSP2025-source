
#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005],c[10005];
int sum[10005];
int ans,e;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        sort(a+n,a+n+1);
    }
    e=n/2;
    for(int i=e;i<=n;i++){
        ans+=a[i];
        }
    cout<<ans;
    }
    return 0;
}

