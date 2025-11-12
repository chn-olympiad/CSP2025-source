#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[203];
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,a1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    a1=a[1];
    sort(a+1,a+n*m+1,cmp);
    int id;
    for(int i=1;i<=n*m;i++)
    if(a1==a[i]){
        id=i;
        break;
    }
    id--;
    int p=id/n,q=id%n;
    if(p%2){
        cout<<p+1<<' '<<m-q<<'\n';
        return 0;
    }
    else{
        cout<<p+1<<' '<<q+1<<'\n';
        return 0;
    }
    return 0;
}
//file memory long long
