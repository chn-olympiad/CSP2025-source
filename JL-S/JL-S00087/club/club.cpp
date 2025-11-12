#include<bits/stdc++.h>

using namespace std;

const int N = 10005;

int a[N],b[N],c[N];

int main (){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        sort(a+1,a+n+1);
        int ans=0;
        for(int i=n;i>(n/2);i++){
            ans+=a[i];
        }
        cout<<ans;
    }
    return 0;
}
