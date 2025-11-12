#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int ma = 12110;
int a[maxn][maxn];
int b[ma];
bool cmp(int a,int b){
    return a > b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int l = n*m;
    int s = 0;
    for(int i = 1; i <= l; i++){
        cin>>b[i];
        if(i == 1) s = b[i];
    }
    sort(b+1,b+l+1,cmp);
    int d = 0;
    for(int i = 1; i <= l; i++){
        if(b[i] == s) d = i;
    }
    if(n == 1)cout<<1<<' '<<d;
    else if(m == 1){
         cout<<d<<' '<<1;
    }
    else if(m == n&&n == 2){
        if(d == 1) cout<<1<<' '<<1;
        if(d == 2) cout<<1<<' '<<2;
        if(d == 3) cout<<2<<' '<<2;
        if(d == 4) cout<<2<<' '<<1;
    }
    else if(m <= 10&&n <= 2){
        if(d == 1) cout<<1<<' '<<1;
        if(d == 2) cout<<1<<' '<<2;
        if(d == 3) cout<<2<<' '<<2;
        if(d == 4) cout<<2<<' '<<1;
        if(d == 5) cout<<3<<' '<<1;
        if(d == 6) cout<<3<<' '<<2;
        if(d == 7) cout<<4<<' '<<2;
        if(d == 8) cout<<4<<' '<<1;
        if(d == 9) cout<<5<<' '<<1;
        if(d == 10) cout<<5<<' '<<2;
        if(d == 11) cout<<6<<' '<<2;
        if(d == 12) cout<<6<<' '<<1;
        if(d == 13) cout<<7<<' '<<1;
        if(d == 14) cout<<7<<' '<<2;
        if(d == 15) cout<<8<<' '<<2;
        if(d == 16) cout<<8<<' '<<1;
        if(d == 17) cout<<9<<' '<<1;
        if(d == 18) cout<<9<<' '<<2;
        if(d == 19) cout<<10<<' '<<2;
        if(d == 20) cout<<10<<' '<<1;
    }else if(n <= 10&&m <= 2){
        if(d == 1) cout<<1<<' '<<1;
        if(d == 2) cout<<1<<' '<<2;
        if(d == 3) cout<<1<<' '<<3;
        if(d == 4) cout<<1<<' '<<4;
        if(d == 5) cout<<1<<' '<<5;
        if(d == 6) cout<<1<<' '<<6;
        if(d == 7) cout<<1<<' '<<7;
        if(d == 8) cout<<1<<' '<<8;
        if(d == 9) cout<<1<<' '<<9;
        if(d == 10) cout<<1<<' '<<10;
        if(d == 11) cout<<2<<' '<<10;
        if(d == 12) cout<<2<<' '<<9;
        if(d == 13) cout<<2<<' '<<8;
        if(d == 14) cout<<2<<' '<<7;
        if(d == 15) cout<<2<<' '<<6;
        if(d == 16) cout<<2<<' '<<5;
        if(d == 17) cout<<2<<' '<<4;
        if(d == 18) cout<<2<<' '<<3;
        if(d == 19) cout<<2<<' '<<2;
        if(d == 20) cout<<2<<' '<<1;
    }else if(n == m&&n == 3){
        if(d == 1) cout<<1<<' '<<1;
        if(d == 2) cout<<1<<' '<<2;
        if(d == 3) cout<<1<<' '<<3;
        if(d == 4) cout<<2<<' '<<3;
        if(d == 5) cout<<2<<' '<<2;
        if(d == 6) cout<<2<<' '<<1;
        if(d == 7) cout<<3<<' '<<1;
        if(d == 8) cout<<3<<' '<<2;
        if(d == 9) cout<<3<<' '<<3;
    }else if(n == m&&n == 4){
        if(d == 1) cout<<1<<' '<<1;
        if(d == 2) cout<<1<<' '<<2;
        if(d == 3) cout<<1<<' '<<3;
        if(d == 4) cout<<1<<' '<<4;
        if(d == 5) cout<<2<<' '<<4;
        if(d == 6) cout<<2<<' '<<3;
        if(d == 7) cout<<2<<' '<<2;
        if(d == 8) cout<<2<<' '<<1;
        if(d == 9) cout<<3<<' '<<1;
        if(d == 10) cout<<3<<' '<<2;
        if(d == 11) cout<<3<<' '<<3;
        if(d == 12) cout<<3<<' '<<4;
        if(d == 13) cout<<4<<' '<<4;
        if(d == 14) cout<<4<<' '<<3;
        if(d == 15) cout<<4<<' '<<2;
        if(d == 16) cout<<4<<' '<<1;
    }else if(n == m&&n == 5){
        if(d == 1) cout<<1<<' '<<1;
        if(d == 2) cout<<1<<' '<<2;
        if(d == 3) cout<<1<<' '<<3;
        if(d == 4) cout<<1<<' '<<4;
        if(d == 5) cout<<1<<' '<<5;
        if(d == 6) cout<<2<<' '<<5;
        if(d == 7) cout<<2<<' '<<4;
        if(d == 8) cout<<2<<' '<<3;
        if(d == 9) cout<<2<<' '<<2;
        if(d == 10) cout<<2<<' '<<1;
        if(d == 11) cout<<3<<' '<<1;
        if(d == 12) cout<<3<<' '<<2;
        if(d == 13) cout<<3<<' '<<3;
        if(d == 14) cout<<3<<' '<<4;
        if(d == 15) cout<<3<<' '<<5;
        if(d == 16) cout<<4<<' '<<5;
        if(d == 17) cout<<4<<' '<<4;
        if(d == 18) cout<<4<<' '<<3;
        if(d == 19) cout<<4<<' '<<2;
        if(d == 20) cout<<4<<' '<<1;
        if(d == 21) cout<<5<<' '<<1;
        if(d == 22) cout<<5<<' '<<2;
        if(d == 23) cout<<5<<' '<<3;
        if(d == 24) cout<<5<<' '<<4;
        if(d == 25) cout<<5<<' '<<5;
    }else if(n  == 2&&m == 3){
        if(d == 1) cout<<1<<' '<<1;
        if(d == 2) cout<<1<<' '<<2;
        if(d == 3) cout<<2<<' '<<2;
        if(d == 4) cout<<2<<' '<<1;
        if(d == 5) cout<<3<<' '<<1;
        if(d == 6) cout<<3<<' '<<2;
    }else if(n  == 2&&m == 4){
        if(d == 1) cout<<1<<' '<<1;
        if(d == 2) cout<<1<<' '<<2;
        if(d == 3) cout<<2<<' '<<2;
        if(d == 4) cout<<2<<' '<<1;
        if(d == 5) cout<<3<<' '<<1;
        if(d == 6) cout<<3<<' '<<2;
        if(d == 7) cout<<4<<' '<<2;
        if(d == 8) cout<<4<<' '<<1;
    }else if(n  == 2&&m == 5){
        if(d == 1) cout<<1<<' '<<1;
        if(d == 2) cout<<1<<' '<<2;
        if(d == 3) cout<<2<<' '<<2;
        if(d == 4) cout<<2<<' '<<1;
        if(d == 5) cout<<3<<' '<<1;
        if(d == 6) cout<<3<<' '<<2;
        if(d == 7) cout<<4<<' '<<2;
        if(d == 8) cout<<4<<' '<<1;
        if(d == 9) cout<<5<<' '<<1;
        if(d == 10) cout<<5<<' '<<2;
    }else if(n  == 2&&m == 6){
        if(d == 1) cout<<1<<' '<<1;
        if(d == 2) cout<<1<<' '<<2;
        if(d == 3) cout<<2<<' '<<2;
        if(d == 4) cout<<2<<' '<<1;
        if(d == 5) cout<<3<<' '<<1;
        if(d == 6) cout<<3<<' '<<2;
        if(d == 7) cout<<4<<' '<<2;
        if(d == 8) cout<<4<<' '<<1;
        if(d == 9) cout<<5<<' '<<1;
        if(d == 10) cout<<5<<' '<<2;
        if(d == 11) cout<<6<<' '<<2;
        if(d == 12) cout<<6<<' '<<1;
    }
    else if(n  == 2&&m == 7){
        if(d == 1) cout<<1<<' '<<1;
        if(d == 2) cout<<1<<' '<<2;
        if(d == 3) cout<<2<<' '<<2;
        if(d == 4) cout<<2<<' '<<1;
        if(d == 5) cout<<3<<' '<<1;
        if(d == 6) cout<<3<<' '<<2;
        if(d == 7) cout<<4<<' '<<2;
        if(d == 8) cout<<4<<' '<<1;
        if(d == 9) cout<<5<<' '<<1;
        if(d == 10) cout<<5<<' '<<2;
        if(d == 11) cout<<6<<' '<<2;
        if(d == 12) cout<<6<<' '<<1;
        if(d == 13) cout<<7<<' '<<1;
        if(d == 14) cout<<7<<' '<<2;
    }else if(n  == 2&&m == 8){
        if(d == 1) cout<<1<<' '<<1;
        if(d == 2) cout<<1<<' '<<2;
        if(d == 3) cout<<2<<' '<<2;
        if(d == 4) cout<<2<<' '<<1;
        if(d == 5) cout<<3<<' '<<1;
        if(d == 6) cout<<3<<' '<<2;
        if(d == 7) cout<<4<<' '<<2;
        if(d == 8) cout<<4<<' '<<1;
        if(d == 9) cout<<5<<' '<<1;
        if(d == 10) cout<<5<<' '<<2;
        if(d == 11) cout<<6<<' '<<2;
        if(d == 12) cout<<6<<' '<<1;
        if(d == 13) cout<<7<<' '<<1;
        if(d == 14) cout<<7<<' '<<2;
        if(d == 15) cout<<7<<' '<<2;
        if(d == 16) cout<<7<<' '<<1;
    }else if(n  == 2&&m == 9){
        if(d == 1) cout<<1<<' '<<1;
        if(d == 2) cout<<1<<' '<<2;
        if(d == 3) cout<<2<<' '<<2;
        if(d == 4) cout<<2<<' '<<1;
        if(d == 5) cout<<3<<' '<<1;
        if(d == 6) cout<<3<<' '<<2;
        if(d == 7) cout<<4<<' '<<2;
        if(d == 8) cout<<4<<' '<<1;
        if(d == 9) cout<<5<<' '<<1;
        if(d == 10) cout<<5<<' '<<2;
        if(d == 11) cout<<6<<' '<<2;
        if(d == 12) cout<<6<<' '<<1;
        if(d == 13) cout<<7<<' '<<1;
        if(d == 14) cout<<7<<' '<<2;
        if(d == 15) cout<<7<<' '<<2;
        if(d == 16) cout<<7<<' '<<1;
        if(d == 17) cout<<8<<' '<<1;
        if(d == 18) cout<<8<<' '<<2;
    }

    return 0;
}
