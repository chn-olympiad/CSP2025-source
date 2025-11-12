#include<bits/stdc++.h>
using namespace std;
int m,n,a[101];
bool cmp(int A,int B){
    return A > B;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> a[i];
    }
    int ans = a[1];
    sort(a + 1,a + n * m + 1,cmp);
    for(int i = 1;i <= n * m;i++){
        if(a[i] == ans){
            int f;
            if(i % n != 0){
                f = i / n + 1;
            }else{
                f = i / n;
            }
            cout << f << " ";
            if(f % 2 == 1){
                if(i % n != 0){
                    cout << i % n;
                }else{
                    cout << n;
                }
            }else{
                if(i % n == 0){
                    cout << 1;
                }else{
                    cout << n - i % n + 1;
                }
            }
            break;
        }
    }
    return 0;
}
