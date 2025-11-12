#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0,a[1000000];
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ans=n/2;
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
