#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
       cin>>a[i];
    }
    cnt=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    int s=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(a[s++]==cnt){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }else{
            for(int j=n;j>=1;j--){
                if(a[s++]==cnt){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
