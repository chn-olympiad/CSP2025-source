#include <iostream>
#include <string>

using namespace std;

int NumTong[10];

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string input;
    cin >> input;
    int target_size = 0;
    for(char c: input){
        if(c >= '0' && c <= '9'){
            NumTong[c - '0']++;
        }
    }
    
    for(int num = 9; num >= 0; num--){
        //cout << "NumTong[" << num << "] is" << NumTong[num] << endl;
        char NumChar = '0' + num;
        for(int _ = 0; _ < NumTong[num]; _++){
            cout << (char)NumChar;
        }
    }
    return 0;
}