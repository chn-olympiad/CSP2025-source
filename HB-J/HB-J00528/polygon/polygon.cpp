#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],mx;
unsigned long long sum;
bool fd(int l,int r){
    if((b[r]-b[l-1])>mx) return 1;
    return 0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    b[1]=a[1];
    for(int i=2;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    mx=2*a[n];
    if(fd(1,n)==1) sum++;
    cout << (sum%998244353);
    return 0;
}
