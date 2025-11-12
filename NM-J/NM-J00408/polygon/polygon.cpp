#include <bits/stdc++.h>
using namespace std;
int n,a[5000],cnt,he;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        he+=a[i];
    }
    sort(a+1,a+n+1);
    if(he>a[n]*2&&n>=3) cnt++;
    cout<<cnt;
    return 0;
}
