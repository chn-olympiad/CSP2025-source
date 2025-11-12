#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            ans+=max(a,max(b,c));
        }
        cout<<ans<<endl;
    }
    return 0;
}
