#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[110],ida;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    ida=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++)
    if(ida==a[i]){
        ida=i;
        break;
    }
    int x=0,y=1;
    for(int i=1,way=0;i<=ida;i++){
        if(way==0){
            if(x<n)x++;
            else{
                y++;way=1;
            }
        }else{
            if(x>1)x--;
            else{
                y++;way=0;
            }
        }
    }
    cout<<y<<' '<<x;
    return 0;
}
