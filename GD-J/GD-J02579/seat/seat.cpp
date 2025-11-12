#include<bits/stdc++.h>
using namespace std;
const int maxn=10*10+5;
int n,m,rk=-1,a[maxn];
void Main(){
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        rk+=(a[i]>=a[1]);
    }
    int misaka=1,mikoto=1;
    while(rk--){
        if(mikoto&1){
            if(misaka<n){
                misaka++;
            }
            else{
                mikoto++;
            }
        }
        else{
            if(misaka>1){
                misaka--;
            }
            else{
                mikoto++;
            }
        }
    }
    cout<<mikoto<<' '<<misaka<<'\n';
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    Main();
}