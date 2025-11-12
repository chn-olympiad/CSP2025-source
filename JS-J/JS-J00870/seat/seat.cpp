#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
signed main(){
    cin.tie(0);
    cout.tie(0);
    freopen(stdin,"r","seat.in");
    freopen(stdout,"w","seat.out");
    int n,m;
    cin >> n >> m;
    int a[1025],a1;
    fr(i,1,n*m+1)cin >> a[i];
    a1=a[1];
    sort(a+1,a+1+n*m);
    reverse(a+1,a+1+n*m);
    int pos=0;
    fr(i,1,n*m+1)if(a[i]==a1){
        pos=i;
        break;
    }
    int b=pos%(2*n),c=pos/(2*n),ans1=0,ans2;
    if(b>n)ans2=2*n+1-b,ans1=2;
    else ans2=b,ans1=1;
    ans1+=c*2;
    cout << ans1 << ' ' << ans2;
    return 0;
}
/*
& &
(~)
written by Leon2012
I love CCF!
I'm going to AK CSP-J/S!
*/
