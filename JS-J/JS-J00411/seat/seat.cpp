#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdio>
using namespace std;

typedef long long ll;
int n,m;
int a[1005],base;

int main (){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n*m;i++){
        cin >> a[i];
    }
    base=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    int pos=0;
    for (int i=1;i<=n*m;i++){
        if (a[i]==base){
            pos=i;
            break;
        }
    }
    int c=pos/n+1,r=pos%n;
    if (r==0){
        c--;
        r=n;
    }
    if (c%2==0){
        r=n-r+1;
    }
    cout << c << ' ' << r << endl;
    return 0;
}
//upd:wangjishenmeshihoule duipaizhaochuyigecuo
//CSP rp++