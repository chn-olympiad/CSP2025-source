#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],tot,rScr,rPlc,plc;
bool cmp(int x,int y){
    return x>y;
}int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    tot=n*m;
    for(int i=1;i<=tot;i++)cin>>a[i];
    rScr=a[1];
    sort(a+1,a+tot+1,cmp);
    for(int i=1;i<=tot;i++){
        if(a[i]==rScr){
            rPlc=i;
            break;
        }
    }int j=1;
    while(plc<=tot){
        if(j%2){
            for(int i=1;i<=n;i++){
                plc++;
                if(plc==rPlc){
                    cout<<j<<' '<<i;
                    return 0;
                }
            }
        }else{
            for(int i=n;i>=1;i--){
                plc++;
                if(plc==rPlc){
                    cout<<j<<' '<<i;
                    return 0;
                }
            }
        }j++;
    }return 0;
}
