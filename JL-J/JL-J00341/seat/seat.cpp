#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdin);
    int p,H,R,T,T2,T3,T4;
    cin>>p>>H>>R>>T>>T2>>T3;
    if(R>T){
        if(R>T2){
            if(R>T3){
                    cout<<1<<endl;
                }
                else{
                    cout<<1+1<<endl;
                }
            }
            else{
                if(R>T3){
                    cout<<1+1;
                }
                else{
                    cout<<p*H-1<<endl;
                }
            }
        }
        else{
            if(R>T2){
                if(R>T3){
                    cout<<1+1<<endl;
                }
                else{
                    cout<<p*H-1<<endl;
                }
            }
            else{
                    if(R>T3){
                        cout<<p*H-1<<endl;
                    }
                    else{
                cout<<p*H<<endl;
                    }
            }
        }
    return 0;
}
