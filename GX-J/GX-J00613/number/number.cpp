#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    int a[1000001], j0 = 0;
    cin>>s;

    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            a[j0] = int(s[i] - '0');
            ++j0;
        }
    }

    for(int i = 0; i < j0+1; i++){
        for(int j = 0; j < j0+1; j++){
            if(a[j+1] > a[j]){
                int t = a[j+1];
                a[j+1] = a[j];
                a[j] = t;
            }
        }
    }

    for(int i = 0; i < j0+1; i++){
        cout<<a[i];
    }

    return 0;
}
