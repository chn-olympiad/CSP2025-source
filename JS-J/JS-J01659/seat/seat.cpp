#include <bits/stdc++.h>
using namespace std;

int n, m, a[107], r, cnt, xx, yy;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=0;i<n*m;i++){
        cin>>a[i];
    }
    r=a[0];
    for (int i=1;i<n*m;i++){
        if (a[i]>r) cnt++;
    }
    xx=cnt/n+1;
    yy=cnt%n+1;
    if (xx%2==0){
        yy=n-(yy-1);
    }
    cout<<xx<<" "<<yy<<endl;
    return 0;
}

