#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++){
        cin>>f[i];
    }
    int k=1;
    for(int i = 1;i <= n*m;i++){
        if(f[i] > f[1]){
            k++;
        }
    }
    for(int i = 1;i <= m;i++){

        if(n*(i-1) < k && n*i >= k){
            cout << i <<' ';

            if(i%2 == 1){
                cout << k - n*(i-1);
            }else{
                cout << n*i - k + 1;
            }
        }

    }
    return 0;
}
