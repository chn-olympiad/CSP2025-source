#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 1000;
const int M = INT_MAX;

int n , k;
int a[N];
string s[N] , s1[N];
int b[M];
int c , sc;
int ans;

string ttoe(int a1){
    string sa = "";
    if(a1 >= 128){
        a1 -= 128;
        sa += '1';
    }else{
        sa += '0';
    }
    if(a1 >= 64){
        a1 -= 64;
        sa += '1';
    }else{
        sa += '0';
    }
    if(a1 >= 32){
        a1 -= 32;
        sa += '1';
    }else{
        sa += '0';
    }
    if(a1 >= 16){
        a1 -= 16;
        sa += '1';
    }else{
        sa += '0';
    }
    if(a1 >= 8){
        a1 -= 8;
        sa += '1';
    }else{
        sa += '0';
    }
    if(a1 >= 4){
        a1 -= 4;
        sa += '1';
    }else{
        sa += '0';
    }
    if(a1 >= 2){
        a1 -= 2;
        sa += '1';
    }else{
        sa += '0';
    }
    if(a1 == 1){
        sa += '1';
    }else{
        sa += '0';
    }
    return sa;
}

int main(){
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }


    //////
    if(k == 0){
        cout << "1";
        return 0;
    }
    if(k == 1){
        int lin = 0;
        for(int i = 1 ; i <= n ; i++){
            if(a[i] == 1){
                lin++;
            }
        }
        if(lin == 0){
            cout << "0";
            return 0;
        }else{
            cout << "1"
        }
    }
    //////

    for(int i = 1 ; i <= n ; i++){
        s[i] = ttoe(a[i]);
        s1[i] = s[i];
    }

    for(int l = 1 ; l <= n ; l++){
        for(int r = l ; r <= n ; r++){
            if(r == l){
                b[c] = a[r];
                r++;
                c++;
            }
            for(int i = l ; i < r - l + 1 ; i++){
                for(int j = 0 ; j < 8 ; j++){
                    if(s[i][j] == s[i + 1][j]){
                        s[i + 1][j] = 0;
                    }else{
                        s[i + 1][j] = 1;
                    }
                }
            }
        }
    }
    return 0;
}