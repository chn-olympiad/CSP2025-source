#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,ans=0,club1[100005],club2[100005],club3[100005];
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>club1[i]>>club2[i]>>club3[i];
        }
        if(club2[1]!=0){
            sort(club1+1,club1+n+1);
            sort(club2+1,club2+n+1);
            for(int i=1;i<=n/2;i++){
                ans+=club1[n-i+1];
                ans+=club2[n-i+1];
            }
            cout<<ans<<endl;
            continue;
        }
        sort(club1+1,club1+n+1);
        for(int i=1;i<=n/2;i++){
            ans+=club1[n-i+1];
        }
        cout<<ans<<endl;
    }
    return 0;
}
