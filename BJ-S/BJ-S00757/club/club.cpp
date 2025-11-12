#include<bits/stdc++.h>
using namespace std;
int t,n,a1[100005],a2[100005],a3[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a1[i]>>a2[i]>>a3[i];
        int ans=0;
        int c1,c2,c3;
        for(int i=1;i<=n;i++){
            int f=0;
            int mx=max(a1[i],max(a2[i],a3[i]));
            if(mx==a1[i])f=1;
            else if(mx==a2[i])f=2;
            else f=3;
            if(f==1&&c1<=n/2){
                ans+=mx;
                c1++;
            }
            if(f==2&&c2<=n/2){
                ans+=mx;
                c2++;
            }
            if(f==3&&c3<=n/2){
                ans+=mx;
                c3++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
