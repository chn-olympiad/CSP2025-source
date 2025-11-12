#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c;
long long ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=a=b=c=0;
        cin>>n;
        while(n--){
            cin>>a>>b>>c;
            ans+=max({a,b,c});
        }
        cout<<ans<<endl;;
    }
    return 0;
}
//T1出dp???
//?????
