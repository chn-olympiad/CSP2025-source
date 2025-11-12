#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int a = int(s);
    int q[1000000];
    int qq = 1;
    while(1){
        q[qq] = a%10;
        qq++;
        a = a%10;
        if(a == 0) break;
    }

    sort(q+1, q+qq+1);
    for(int i = 1; i <= qq; i++){
        cout << q[i];
    }
    return 0;
}

