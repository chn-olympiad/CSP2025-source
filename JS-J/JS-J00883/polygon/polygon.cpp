#include <bits/stdc++.h>
using namespace std;
int a[5500];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                if(i+j>k){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
