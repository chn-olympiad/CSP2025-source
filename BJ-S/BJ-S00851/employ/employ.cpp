#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ull n,s=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        s*=i;
        s=s%998244353;
    }
    cout<<s;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
