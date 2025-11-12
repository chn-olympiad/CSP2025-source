#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    char a[1000005];
    cin.getline(a, 1000005);
    int c;
    int x = 0;
    int b = strlen(a);
    int d[b+5];
    for(int i = 0;i < b;i++){
        if(a[i] >= '0' && a[i] <= '9'){
            c = a[i];
            d[x] = c - 48;
            x++;
        }
    }
    for(int j = 0;j < x;j++){
        for(int i = 0;i < x;i++){
            if(d[i] < d[i+1]){
                int v = d[i];
                d[i] = d[i+1];
                d[i+1] = v;
            }
        }
    }
    for(int i = 0;i < x;i++){
        cout << d[i];
    }
    return 0;
}
