#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],shu,q,x=0,y=1;
bool t=1;
bool cmp(int a1,int a2){
    return a1>a2;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    shu=n*m;
    for(int i=1;i<=shu;i++){
        cin>>a[i];
    }
    q=a[1];
    sort(a+1,a+shu+1,cmp);
    for(int i=1;i<=shu;i++){
        if((i-1)%n!=0||i==1){
            if(t==1){
                x++;
            }else{
                x--;
            }
        }else{
            t=1-t;
            y++;
        }
//        cout<<a[i]<<" "<<x<<" "<<y<<" "<<t<<" "<<endl;
        if(a[i]==q){
            cout<<y<<" "<<x;
            return 0;
        }
    }
    return 0;
}

