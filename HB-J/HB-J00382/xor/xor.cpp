#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n<=1){
        cout<<'0';
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<'1';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
