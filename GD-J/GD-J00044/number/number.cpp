#include <bits/stdc++.h>

using namespace std;

int arr[1000000];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int i1 = 0;
    for(int i = 0;i < s.size();i++){
        if(isdigit(s[i])){
            arr[i1++] = (int)(s[i] - '0');
        }
    }
    sort(arr,arr + i1);
    for(int i = i1 - 1;i >= 0;i--){
        cout << arr[i];
    }
    return 0;
}

