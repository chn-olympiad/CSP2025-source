#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=3;i--){
        for(int j=i-1;j>=1;j--){
            int x=a[j];
            for(int k=j-1;k>=1;k--){
                if(x+a[k]>a[i]){
                    cnt+=k;
                }
                else{
                    x+=a[k];
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
