#include <iostream>
#include <string>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
string s;
i64 a[60];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int len = s.length();
    for(int i = 0;i < len;i++){
        if(!(isalpha(s[i]))){
            a[int(s[i])]++;
        }
    }
    for(int i = 57;i >= 48;i--){
        for(int j = 1;j <= a[i];j++){
            cout << char(i);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
