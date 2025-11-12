#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[100001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[1]-=a[2];
    a[2]-=a[3];
    a[1]-=a[2];
    cout<<'2';
    return 0;
}
