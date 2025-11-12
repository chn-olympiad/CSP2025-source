#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string str;
    cin >> str;
    vector<int> a(10,0);
    for(int i = 0;i<str.size();i++){
        char ch = str[i];
        if(ch>='0' && ch<='9'){
            a[ch-'0']++;
        }
    }

    for(int i = 9;i>=0;i--){
        for(int j = 0;j<a[i];j++){
            cout <<i;
        }
    }



    return 0;
}
