#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int cnt=-1;
int ans;
int a[100010][10];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int ii=1;ii<=n;ii++){
                cnt=-1;
            for(int jj=1;jj<=3;jj++){
                cin>>a[ii][jj];
                cnt=max(cnt,a[ii][jj]);

            }
            ans+=cnt;

        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
