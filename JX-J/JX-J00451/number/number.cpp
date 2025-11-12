#include <iostream>
using namespace std;
int main(){
    freopen("number.in",r,"stdin");
    freout("number.out",w,"stdout");
    string s;
    string num[1000];
    cin >> s;
    for (int i = 0;i<=1000;i++){
        if (s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            num[i] = s[i];
        }
    }
    for (int u = 0;u<=1000;u++){
        for (int j = 0;j<=1000;j++){
            if (num[j]>num[j-1]){
                string h = num[j];
                num[j] = num[j-1];
                num[j-1] = h;
            }
        }
    }
    for (int y = 0;y<=1000;y++){
        cout << num[y];
    }
    return 0;
}
