#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[15][15],b[105];
    int littleR,pl;
    cin >> littleR;
    b[1] = littleR;
    for(int i = 2;i <= n * m;i++){
        cin >> b[i];
    }
    sort(b + 1,b + n * m + 1,cmp);
    for(int i = 1;i <= n * m;i++){
        if(b[i] == littleR){
            pl = i;
            int pln;
            if(pl % n == 0){
                pln = pl / n;
            }
            else{
                pln = pl / n + 1;
            }
            cout << pln << ' ';
            if(pln % 2 == 0){
                cout << n - (pl - 1) % n;
            }
            else{
                if(pl % n == 0){
                    cout << n;
                }
                else{
                    cout << pl % n;
                }
            }
        }

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
