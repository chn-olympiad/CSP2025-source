#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,r_1,b=0,seat=0,ans_n=0,ans_m=0;
    cin>>n>>m;
    int a=n*m;
    cin>>r_1;
    for(int i=1;i<a;i++){
        cin>>r;
        b=r;
        if(b>=r_1) seat++;
    }
    if(seat>=0){
        seat+=1;
        if(seat%n==0){
            if(seat/n%2==0) {
                if(seat%n==0) ans_n=1;
                else ans_n=n-(seat-1)%n;
            }
            else ans_n=n;
            ans_m=seat/n;
        }
        else {
            if((seat/n+1)%2==0) {
                ans_n=n-(seat-1)%n;
                ans_m=seat/n+1;
            }
            else {
                ans_n=seat%n;
                ans_m=seat/n+1;
            }
        }
    }

    cout<<ans_m<<" "<<ans_n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
