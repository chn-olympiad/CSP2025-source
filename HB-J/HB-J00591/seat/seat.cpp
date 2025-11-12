#include<bits/stdc++.h>
using namespace std;
int ll[12][12];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int l[a*b+1]={};
    for(int i=1;i<=a*b;i++){
        cin>>l[i];
    }
    sort(l+1,l+a*b+1);
    int y[a*b+1]={},r=0,w=0;
    for(int i=a*b;i>0;i--)
        y[i]=l[i];

    for(int j=0;j<b;j++){
        if(w%20==0){
            for(int i=0;i<a;i++){
                ll[i][w]=y[r];
                r++;
            }
        }else{
            for(int i=a;i>0;i--){
                ll[i][w]=y[r];
                r++;
            }
        }
        w++;
    }
    for(int i=0;i<b;i++){
        for(int j=0;j<a;j++){
            if(ll[i][j]==l[1]){
                cout<<i<<" "<<j+2;
            }
        }
    }
    return 0;
}
