#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a, int b) {
    return a > b;
}
int main(){
    freopen("seat.in","r", stdin);
    freopen("seat.out","w", stdout);
    int n, m;
    cin >> n >> m;
    int maxnm = n * m;
    int rs;
    cin >> rs;
    a[1] = rs;
    for (int i = 2 ; i <= maxnm; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + maxnm + 1, cmp);
    int rsi;
    for (int i = 1; i <= maxnm; i ++){
        if(a[i] == rs){
            rsi = i;
            break;
        }
    }
    //cout << rsi << endl;
    int lie = 0; int hang = 0;
    if((rsi % n) != 0){
        lie = (rsi / n) + 1;

        hang = rsi % n;
    }
    else{
        lie = rsi / n;
        hang = n;
    }
    if(lie % 2 == 0) {
        hang = n - rsi % n + 1;
    }
    cout << lie << ' ' << hang;
	return 0;
}
