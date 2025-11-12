#include<iostream>
#include<cstring>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long a[100001] = {},k = 0;
    string s;
    cin >> s;
    for(int i = 0;i < s.length();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            a[k++] = s[i] - '0';
        }
    }
    sort(a,a+k);
    for(int i = k-1;i >= 0;i--){
        cout << a[i];
    }
    return 0;
}

