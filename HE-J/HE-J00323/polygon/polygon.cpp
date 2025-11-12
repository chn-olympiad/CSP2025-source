#include <bits/stdc++.h>
#include <random>
using namespace std;

bool cmd(int a,int b){
    if(a < b) return false;
    else return true;
}

int main(){
    int n,b;
    int c = random_device(1,10);
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a,a+n,cmd)
    for(int i = 0;i < n;i++){
        b+=a[i];
    }
    if(b < a[0]*2){
        cout << c << endl
    }
    cout << c << endl;
    return 0;
}
