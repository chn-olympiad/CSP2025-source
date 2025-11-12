#include<bits/stdc++.h>
using namespace std;
const int N=1E6+10,P=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n;
    cin>>n;
    int ans=1;
    for(int i=1;i<=n;i++)ans=(ans*i)%P;
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
