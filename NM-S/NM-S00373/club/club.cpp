#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        int cnt[5]={};//ji lu sange bumen fenbie zhaole jige
        int a[100005][5];
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            int max1=max(a[i][1],(max(a[i][2],a[i][3])));
            ans+=max1;
        }
        cout<<ans<<endl;

    }
    return 0;
}
