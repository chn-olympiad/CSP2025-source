#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        int x=a[i],m=0;
        for (int j=1;j<=n;j++){
            x+=a[j];
            m++;
            if (m>=3 && x>a[j]){
                cnt++;
            }
        }
    }
    cout<<cnt;
}
