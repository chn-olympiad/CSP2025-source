#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string c;
    cin >> c;
    string s = c + 'A';
    int length = 0;
    while(s[length] != 'A'){
        length++;
    }
    bool type;
    char num[length];
    for(int i = 0;i < length;i++){
        num[i] = s[i];
    }
    int len = 0;
    vector <int> number;
    for(int i = 0;i < length;i++){
        if((int)num[i] <= 59 && (int)num[i] >= 48){
            number.push_back((int)num[i] - 48);
            len++;
        }
    }
    int mid;
    for(int i = 0;i < len;i++){
        for(int j = 0;j < len - i;j++)
            if(number[j] < number[j + 1]){
                mid = number[j];
                number[j] = number[j + 1];
                number[j + 1] = mid;
            }
    }
    for(int i = 0;i < len;i++){
        cout << number[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
