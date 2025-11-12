#include<bits/stdc++.h>

using namespace std;

long long a[500];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long f = n * m;
    for(int i = 1; i <= f ;i++){
        cin>>a[i];
    }
    long long k = a[1];
    sort(a + 1, a + f + 1);
    long long ans = 0;
    long long now = f;
    for(int i = 1; i <= n; i++){
        if(ans == 0){
            for(int j = 1; j <= m; j++){
                if(a[now] == k){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }else{
                    now--;
                }
            }
            ans = 1;
        }else{
            for(int j = m; j >= 1; j--){
                if(a[now] == k){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }else{
                    now--;
                }
            }
            ans = 0;
        }
    }
    return 0;
}
