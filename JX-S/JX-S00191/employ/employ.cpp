#include<bits/stdc++.h>
using namespace std;
int n,m,ls[505];
string q;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>q;
    int ans = 0;
    for(int i=1;i<=n;i++){
        cin>>ls[i];
        ans = max(ans,ls[i]);
    }
    cout<<ans<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
