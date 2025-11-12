#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n * m] = {0};
    for(int i = 0;i < n * m;i++){
        cin >> a[i];
    }
    int num = 0;
    for(int i = 0;i < n * m;i++){
        if(a[i] >= a[0]){
            num++;
        }
    }
    int c = 1,r = 0;
    int ci = 0;
    int d = 1;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            r += d;
            ci++;
            if(r == 0){
                c++;
                r++;
            }
            if(ci == num){
                cout << c << ' ' << r;
                return 0;
            }
        }
        c++;
        d *= -1;
        ci++;
        if(ci == num){
            cout << c << ' ' << r;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
