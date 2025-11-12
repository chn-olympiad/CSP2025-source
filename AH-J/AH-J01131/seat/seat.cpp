#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],pos,x,y;
bool f;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    pos=a[1];
    sort(a+1,a+1+n*m,cmp);
    x=1,y=1;
    for(int i=1;i<=n*m;i++){
        if(a[i]==pos){
            cout<<y<<' '<<x;
            break;
        }
        if(x==1&&f||x==n&&!f){
            y++;
            f=!f;
        }else{
            x+=(f?-1:1);
        }
    }
    return 0;
}
