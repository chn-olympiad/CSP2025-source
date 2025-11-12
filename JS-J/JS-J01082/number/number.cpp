#include <bits/stdc++.h>
using namespace std;

string str;
int arr[10];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    cin >> str;
    for(int ilon = 0;ilon < str.size();ilon ++){
        if(str[ilon] - '0' <= 9 && str[ilon] - '9' <= 0){
            arr[str[ilon] - '0'] ++;
        }
    }
    for(int ilon = 9;ilon >= 0;ilon --){
        for(int jesi = 0;jesi < arr[ilon];jesi ++){
            cout << ilon;
        }
    }
    return 0;
}
