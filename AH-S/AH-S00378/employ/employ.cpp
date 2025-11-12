#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n;
    long long s=1;
    for(int i=1;i<=n;i++){
        s=(s*i)%998244353;
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
