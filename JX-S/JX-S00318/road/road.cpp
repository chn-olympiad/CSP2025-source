#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
#define ll long long
#define endl "\n"
int n , m , k;
int sum , num;
int main(){
    IOS
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1 ; i <= m ; i ++ ) {
        cin >> num >> num >> num;
        sum += num;
    }
    cout << num;
    return 0;
}
