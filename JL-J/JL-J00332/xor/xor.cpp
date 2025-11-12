#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int k,n;
    cin>>n>>k;
    int cnt=0;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==k){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
