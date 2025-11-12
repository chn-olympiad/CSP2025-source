#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x=1,y=1;
    int n,m,w=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1])w++;
    }
    for(int i=1;i<=n*m;){
        while(y!=n){
            y++;
            i++;
            if(i==w)cout<<x<<" "<<y;
        }
        x++;
        i++;
        if(i==w)cout<<x<<" "<<y;
        while(y!=1){
            y--;
            i++;
            if(i==w)cout<<x<<" "<<y;
        }
        x++;
        i++;
        if(i==w)cout<<x<<" "<<y;
    }
    return 0;
}
