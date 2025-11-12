#include <bits/stdc++.h>
using namespace std;
int T,n,a1[100100],a2[100100],a3[100100],ans,cnt1,cnt2,max1,max2,max3;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a1[i]>>a2[i]>>a3[i];
            if(a1[i]>max1) max1=i;
            if(a2[i]>max2) max2=i;
            if(a3[i]>max3) max3=i;
        }

        if(max3==0&&max2==0){
            sort(a1+1,a1+n+1);
            for(int i=1;i<=n/2;i++){
                ans+=a1[i];
            }
            cout<<ans;
            continue;
        }
        if(max3==0){
            for(int i=1;i<=n;i++){
                if(a1[i]>a2[i]) ans+=a1[i];
                else ans+=a2[i];
            }
            cout<<ans;
            continue;
        }
        if(a1[1]>a2[1]&&a1[1]>a3[1]&&a1[1]>a1[2]) ans+=a1[1];
        else if(a2[1]>a1[1]&&a2[1]>a3[1]&&a2[1]>a2[2]) ans+=a2[1];
        else if(a3[1]>a2[1]&&a3[1]>a1[1]&&a3[1]>a3[2]) ans+=a3[1];
        else ans+=max(a1[1],max(a2[1],a3[1]));
        if(a1[2]>a2[2]&&a1[2]>a3[2]&&a1[2]>a1[1]) ans+=a1[1];
        else if(a2[2]>a1[2]&&a2[2]>a3[2]&&a2[2]>a2[1]) ans+=a2[2];
        else if(a3[2]>a2[2]&&a3[2]>a1[2]&&a3[2]>a3[1]) ans+=a3[2];
        else ans+=max(a1[2],max(a2[2],a3[2]));
        cout<<ans;
    }
    return 0;
}
