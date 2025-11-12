#include<bits/stdc++.h>
using namespace std;
int n, a[1000010], t, ji = 1;
string s;
bool pan(char x){
    if(x == '1'){
        return 1;
    }
    if(x == '2'){
        return 1;
    }
    if(x == '3'){
        return 1;
    }
    if(x == '4'){
        return 1;
    }
    if(x == '5'){
        return 1;
    }
    if(x == '6'){
        return 1;
    }
    if(x == '7'){
        return 1;
    }
    if(x == '8'){
        return 1;
    }
    if(x == '9'){
        return 1;
    }
    if(x == '0'){
        return 1;
    }else{
        return false;
    }
}
void huan(char x, int y){
    if(x == '1'){
        a[y] = 1;
    }
    if(x == '2'){
        a[y] = 2;
    }
    if(x == '3'){
        a[y] = 3;
    }
    if(x == '4'){
        a[y] = 4;
    }
    if(x == '5'){
        a[y] = 5;
    }
    if(x == '6'){
        a[y] = 6;
    }
    if(x == '7'){
        a[y] = 7;
    }
    if(x == '8'){
        a[y] = 8;
    }
    if(x == '9'){
        a[y] = 9;
    }
    if(x == '0'){
        a[y] = 0;
    }
    return;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    t = s.size();
    for(int i = 0;i < t;i++){
        if(pan(s[i])){
            huan(s[i], ji);
            ji++;
        }
    }
    sort(a, a+ji);
    for(int i = ji-1;i >= 1;i--){
        cout << a[i];
    }
    return 0;
}
