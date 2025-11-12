#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005], id, se, ans1, cnt, ans2;
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin>>n>>m;
    for (int i=1; i<=n*m; i++) cin>>a[i];
    id=a[1];
    sort(a+1, a+1+n*m, greater<int>() );
    //for (int i=1; i<=n*m; i++) cout<<a[i]<<" ";
    //cout<<endl;
    for (int i=1; i<=n*m; i++)
        if (a[i]==id)
            se=i;
    ans1=(int(se/n))+1, cnt=se%(n*2);
    if (cnt==0) ans2=1, ans1--;
    else if (cnt>n) {
        //ans1++;
        ans2=cnt-n+1;
    }else {
        ans2=cnt;
        if (ans1==2) ans1--;
    }
    if (ans1==0) ans1++;
    cout<<ans1<<" "<<ans2;
    return 0;
}
