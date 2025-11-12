#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin >> s;
    for(auto p : s){
        int u = int(p) - '0';
        a[u]++;
    }


    for(int i = 9;i >= 0;i--){
        int n = a[i];
        while(n--){
            cout << i;
        }

    }



    return 0;
}
