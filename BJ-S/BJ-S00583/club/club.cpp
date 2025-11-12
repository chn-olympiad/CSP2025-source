#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){return x>y;}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+5];
        for(int i=1;i<=n;i++){
            int u;
            cin>>a[i]>>u>>u;
        }
        sort(a+1,a+n+1,cmp);
        long long ans=0;
        for(int i=1;i<=n/2;i++) ans+=a[i];
        cout<<ans<<endl;
    }
    return 0;
}
