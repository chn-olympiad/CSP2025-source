#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            int x=i|j;
            if (x==k)
                cnt++;
        }
    }
    cout<<cnt;
}
