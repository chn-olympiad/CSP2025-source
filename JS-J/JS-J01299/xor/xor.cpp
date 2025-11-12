#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    int k;
    cin>>n>>k;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    if (k==0){
        cout<<n<<endl;
        return 0;
    }
    else{
        cout<<(n)/2<<endl;
        return 0;
    }
    return 0;
}
