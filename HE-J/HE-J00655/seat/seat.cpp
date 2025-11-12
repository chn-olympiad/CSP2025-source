#include <bits/stdc++.h>
using namespace std;
int a[105],n,m,tt;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n*m;i++) cin >> a[i];
    tt=a[1];
    sort(a+1,a+n*m+1,cmp);
    for (int i=1;i<=n*m;i++){
        if (a[i]==tt){
            tt=i;
            break;
        }
    }
    cout << tt/n+min(1,tt%n) << " ";
    if (tt/n%2==0) cout << max(1,tt%n);
    else{
        int x=tt%n;
        if (x==0) cout << n;
        else cout << n-x+1;
    }
    return 0;
}
