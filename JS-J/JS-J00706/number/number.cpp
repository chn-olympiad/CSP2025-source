#include <iostream>
#include <cstdio>
using namespace std;
string s;
int numbers[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int sizeOfs = s.size();
    for(int i = 0;i < sizeOfs;i++){
        if('0' <= s[i]&&s[i] <= '9'){
            numbers[s[i] - '0']++;
        }
    }
    for(int i = 9;i >= 0;i--)for(int j = 0;j < numbers[i];j++)cout << i;
    return 0;
}
