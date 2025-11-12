#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin >> a;
    for (int i = 1;i < 10000;i++){
        if (a[i] > a[i-1]){
            int s = a[i];
            a[i]= a[i-1];
            a[i-1] = s;
        }
    }
    cout << a;
    return 0;
}
