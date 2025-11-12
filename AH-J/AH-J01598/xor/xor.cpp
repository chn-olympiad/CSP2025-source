#include <bits/stdc++.h>
using namespace std;
long long n,k,sum=0;
long long a[51000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==k){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
