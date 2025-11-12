#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int s2[1001];
    int number = 0;
    for(int i = 1;i <= s.size();i ++){
        if((int)s[i] >= 49 && (int)s[i] <= 57){
            number ++;
            s2[number] = (int)s[i];
        }
    }
    sort(s2[1],s2[number+1]);
    for(int i = number;i >= 1;i --){
        cout << (char)s2[i];
    }
    freopen("number.in","r",stdin);
    fclose("w",stdout);
    return 0;
}
