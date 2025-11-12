#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) n--;
    }
    cout<<n/2;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
