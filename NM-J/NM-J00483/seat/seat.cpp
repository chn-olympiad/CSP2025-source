#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("seat.in","stdin","r");
    freopen("seat.out","stdout","w");
    int p=1;
    int n,m;
    cin>>n>>m;
    int rn=1,rm=1;
    int R,r;
    cin>>R;
    for(int i=1;i<=n*m-1;i++){
        cin>>r;
        if(r>R){
            if(p==1){
                if(rm==m){
                    rn++;
                    p=0;
                }
                else{
                    rm++;
                }
            }
            else{
                if(rm==1){
                    rn++;
                    p=1;
                }
                else{
                    rm--;
                }
            }
        }
    }
    cout<<rn<<' '<<rm;
    return 0;
}
