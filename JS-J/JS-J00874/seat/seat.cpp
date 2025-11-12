#include<bits/stdc++.h>
using namespace std;

long long a[110];

bool cmp(int x, int y){
    return x > y;
}

int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    long long n,m;
    cin >> n >> m;
    for (int i = 1; i <= n*m; i++) cin >> a[i];
    long long ans = a[1];

    sort(a+1,a+n*m+1,cmp);

    for (int i = 1; i <= n*m; i++){
        if (a[i] == ans){

            //cout << a[i] << " " << i << endl;

            int r,c;
            c = (i-1)/n+1;
            r = i-(c-1)*n;
            if (c%2 == 1){
                cout << c << " " << r;
                return 0;
            }
            else{
                r = n+1-r;
                cout << c << " " << r;
                return 0;
            }
        }
    }

    return 0;
}
