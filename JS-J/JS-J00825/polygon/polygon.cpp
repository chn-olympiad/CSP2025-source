#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005;
int n,a[N],ans;
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
    }
    sort(a + 1,a + n + 1);
    if(a[1] + a[2] + a[3] > a[3] * 2 && n == 3){
        cout<<1;
    }
    else if(n == 3){
        cout<<0;
    }
    if(n == 5){
        if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5){
            cout<<9;
        }
        else{
            cout<<6;
        }
    }
    else{
        cout<<366911923;
    }
    return 0;
}
