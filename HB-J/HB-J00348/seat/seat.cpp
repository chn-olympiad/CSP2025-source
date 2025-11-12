#include<bits/stdc++.h>
using namespace std;
#define var long long
#define ln '\n'

const var MaxN=110;
var n,m;
var a[MaxN];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(var i=0;i<n*m;i++){
        cin>>a[i];
    }

    var t=a[0],s=-1;

    sort(a,a+n*m,greater<var>());

    for(var i=0;i<n*m;i++){
        if(a[i]==t){
            s=i;
            break;
        }
    }

    var x=s/n+1;
    var y=0;
    if(x&1){
        y=s%n+1;
    }else{
        y=n-s%n;
    }

    cout<<x<<" "<<y<<ln;
    return 0;
}
