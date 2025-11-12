#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1005],s,R,pm;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n*m;i++){
            s = i;
            cin>>a[s];
            if(i==1)R=a[s];
    }
    sort(a+1,a+s+1);
    for(int i = 1;i<=s;i++){
        if(a[i]==R)pm=s-i+1;
    }
    if(pm%n==0){
        if(pm/n%2==0)cout<<pm/n<<" "<<1;
        else cout<<pm/n<<" "<<n;
    }
    else {
        if(pm/n%2==1){
            cout<<pm/n+1<<" "<<n-pm%n+1;
        }
        else {
            cout<<pm/n+1<<" "<<pm%n;
        }
    }
    return 0;
}
