#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[5][100005],ans,maxn[5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[1][i]>>a[2][i]>>a[3][i];
            ans+=max(a[1][i],max(a[2][i],a[3][i]));
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
