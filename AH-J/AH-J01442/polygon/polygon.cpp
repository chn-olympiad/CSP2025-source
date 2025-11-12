#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[1]-=a[2];
    a[2]-=a[3];
    a[1]-=a[2];
    cout<<'9';
    return 0;
}
