#include <iostream>
#include <cstring>

using namespace std;

string s,ans;
int num[12];

int main(){

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin >> s;

    for(char i : s ) {
        if(i == '0'){
            num[0]++;
        }
                if(i == '1'){
            num[1]++;
        }
                if(i == '2'){
            num[2]++;
        }
                if(i == '3'){
            num[3]++;
        }
                if(i == '4'){
            num[4]++;
        }
                if(i == '5'){
            num[5]++;
        }
                if(i == '6'){
            num[6]++;
        }
                if(i == '7'){
            num[7]++;
        }
                if(i == '8'){
            num[8]++;
        }
                if(i == '9'){
            num[9]++;
        }
    }

    for(int i = 9; i >= 0; i--){
        for(int j = num[i]; j > 0; j--){
            ans += i + '0';
        }
    }

    cout << ans;

    return 0;
}
