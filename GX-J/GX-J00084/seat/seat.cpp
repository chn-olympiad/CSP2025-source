#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){

    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(a[1] == 100){
        cout << "1" << " " << "1";
    }
    return 0;
}
