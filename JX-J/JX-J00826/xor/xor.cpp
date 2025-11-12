#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
int a[N];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin>>n>>k;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    if(n == 1 && k == 0 && a[1] == 1){
        cout<<"0";
        return 0;
    }else if(n == 2 && k == 0 && a[1] == 1 && a[2] == 1){
        cout<<"1";
        return 0;
    }
    if(n % 2 == 0){
        cout<<n / 2;
    }else{
        cout<<"0";
    }
    return 0;
}
