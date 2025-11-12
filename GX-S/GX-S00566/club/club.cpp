#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100010][3],c1,c2,c3,ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","r",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j][0]>>a[j][1]>>a[j][2];
            if(a[j][0]>=a[j][1]&&a[j][0]>=a[j][2]&&c1<=n/2){
                c1++;
                ans+=a[j][0];
            }
            else if(a[j][1]>=a[j][0]&&a[j][1]>=a[j][2]&&c2<=n/2){
                c2++;
                ans+=a[j][1];
            }
            else if(a[j][2]>=a[j][1]&&a[j][2]>=a[j][0]&&c3<=n/2){
                c3++;
                ans+=a[j][2];
            }
        }
        cout<<ans<<endl;
    }
}
