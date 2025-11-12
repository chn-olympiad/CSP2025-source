#include<bits/stdc++.h>
using namespace std;
int cl[100010][3];
int ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int mch=n/2,ch1,ch2;
        int mc=-1;
        for(int i=1;i<=n;i++){
            cin>>cl[i][0]>>cl[i][1]>>cl[i][2];
            ans+=max(cl[i][0],cl[i][1]);
        }

        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
