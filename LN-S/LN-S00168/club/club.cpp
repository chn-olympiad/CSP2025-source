#include<bits/stdc++.h>
using namespace std;
int m[1048576];
int ans = 0;
int n,t;
int a[4];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[j];
            }
            sort(a+1,a+4);
            m[i] = a[3];
        }
        sort(m+1,m+n+1);
        for(int i=n;i>(n/2);i--){
            ans += m[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
