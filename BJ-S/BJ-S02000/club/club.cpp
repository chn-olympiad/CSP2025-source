#include<iostream>
#include<algorithm>
using namespace std;
int t,n,a1[100100],a2[100100],a3[100100],ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i = 1;i <= t;i++){
            ans = 0;
        cin>>n;
        for(int i = 1;i <= n;i++){
            cin>>a1[i]>>a2[i]>>a3[i];
        }
        sort(a1 + 1,a1 + n + 1);
        sort(a2 + 1,a2 + n + 1);
        sort(a3 + 1,a3 + n + 1);
        for(int i = 1;i <= n;i++){
            ans += a1[i];
        }
        cout<<ans;
    }
    return 0;
}
