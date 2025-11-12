#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x = 1,y = 1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n*m;i++) cin>>a[i];
    int scr = a[1];
    sort(a+1,a+n*m+1,[](int p,int q){return p > q;});
    for(int i = 1;i <= n*m;i++){
        if(a[i] == scr) break;
        if(x % 2 != 0){
            if(y == n) x++;
            else y++;
        } else {
            if(y == 1) x++;
            else y--;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
