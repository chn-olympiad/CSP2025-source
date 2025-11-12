#include <bits/stdc++.h>
using namespace std;
int n,m,a[101010],x=1,y=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int t=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            cout<<x<<" "<<y;
            return 0;
        }
        if(x==n) y++;
        else{
            if(y%2!=0) x++;
            else x--;
        }
    }
    return 0;
}
