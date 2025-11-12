#include <bits/stdc++.h>
using namespace std;
int n=0,k=0,b[10001]={0};
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int a=1;a<=n;a++){
        cin>>b[a];
    }
    cout<<k<<b<<n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
