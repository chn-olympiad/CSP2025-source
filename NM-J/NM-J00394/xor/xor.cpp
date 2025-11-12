#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int n, k, a[N],ans;
bool a1[N];

int main (){
//    freopen ("xor.in", "r", stdin);
//    freopen ("xor.out", "w", stdout);
    cin >> n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a1[i]=1;
        if(a[i]==k) ans++,a1[i]=0;
    }
    for(int i=2;i<=n;i++){
        if(a1[i]){
            if(a[i]-a[i+1]==k||a[i]+a[i+1]==k){
                ans++;
                a1[i]=0;
                a1[i+1]=0;
            }
            if(a[i]-a[i-1]==k||a[i]+a[i-1]==k){
                ans++;
                a1[i]=0;
                a1[i-1]=0;
            }

        }
        else continue;
    }
    cout<<ans;
    return 0;
}
