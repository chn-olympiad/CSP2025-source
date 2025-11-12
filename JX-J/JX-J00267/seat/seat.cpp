#include<bits/stdc++.h>
using namespace std;

long long n,m,op,mqw = 1;
long long qw = 0;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin >> n >> m;
    cin >> op;

    for(int i = 1;i <= n*m-1;i++){
        int x;
        cin >> x;
        if(x > op){
            qw++;
        }
    }

    while(1){
        int i = qw + 1;
        if(i <= n){
            if(mqw % 2 != 0){
                cout << mqw << " ";
                cout << i << "\n";
                break;
            }else{
                cout << mqw << " ";
                cout << n-i+1 << "\n";
                break;
            }
        }else{
            qw -= n;
            mqw++;
        }
    }
    return 0;
}
