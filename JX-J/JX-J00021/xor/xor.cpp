#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+5;
int a[N];
int main(){
    freopen( "xor.in" , "r" , stdin);
    freopen( "xor.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n , k;
    cin >> n >> k;
    int cnt = 0;
    int tmp;
    cin >> a[1];
    tmp = a[1];
    for(int i = 2; i <= n; ++i){
        cin >> a[i];
        if(tmp == 0) tmp = a[i];
        else tmp = tmp | a[i];
        if(tmp == k){
            cnt++;
            tmp = 0;
        }

    }
    cout << cnt <<endl;
    return 0;

}
