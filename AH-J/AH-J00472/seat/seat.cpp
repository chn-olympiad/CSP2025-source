#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int jb=a[1],p=0;
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(jb==a[i]){
            p=i;
            break;
        }
    }
    int x=1,y=1;
    p--;
    while(p--){
        if(y%2==1){
            if(x==n)y++;
            else x++;
        }else {
            if(x==1)y++;
            else x--;
        }
    }
    cout<<y<<" "<<x<<endl;
    return 0;
}
