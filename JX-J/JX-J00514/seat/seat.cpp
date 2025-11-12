#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main (){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y;
    int n,m,c;
    int a[105];
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    c=a[0];
    sort(a,a+n*m,cmp);
    x=y=1;
    for(int i=0;i<n*m;i++){
        if(a[i]==c){
                break;
        }
        if(x%2==1){
            y++;
            if(y==n+1){
                y=n;
                x++;
            }
        }else{
            y--;
            if(y==0){
                y=1;
                x++;
            }
        }
    }
    cout<<x<<' '<<y<<'\n';
    return 0;
}
