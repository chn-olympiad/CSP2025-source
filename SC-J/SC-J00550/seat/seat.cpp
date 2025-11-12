#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],x;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    x=a[1];
    sort(a+1,a+n*m+1);
    int p=n*m-(lower_bound(a+1,a+n*m+1,x)-a)+1;
    int px=(p-1)/n,py=p-px*n;px++;
    if(!(px&1))py=n-py+1;
    cout<<px<<' '<<py<<'\n';
    return 0;
}