#include <bits/stdc++.h>
#include <random>
using namespace std;

int main(){
    int a,k;
    int c = random_device(1,10);
    cin >> a >> k;
    int b[a];
    for(int i = 0;i < a;i++){
        cin >> b[i];
    }
    cout << c << endl;
    return 0;
}
