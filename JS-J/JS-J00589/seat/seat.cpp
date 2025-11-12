#include<bits/stdc++.h>
using namespace std;
int mine, m, n, seatOrder = 0, c, r;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>mine;
    int a[m*n];
    for(int i =0;i <m*n;i++){
        cin>>a[i];
    }
    if(mine > a[0]) cout<<1<<' '<<1;
    else{
        for(int i = 0;i < m * n;i++){
            if(mine > a[i]){
                cout<<a[i] % n<<' '<<a[i] % m;
                return 0;
            }
        }
    }
return 0;
}
