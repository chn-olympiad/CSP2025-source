#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int  a[10010] , b[10010];
    cin >> s;
    for(int i = 0 ; i <= 1000 ; i++){
        if(s >= "0" && s <= "9"){
            a[i] = int(s[i]);
        }
        else if(s <= "a" && s <= "z"){
            s[i + 1];
        }
        else{
            break;
        }
    }
    for(int j = 0 ; j < 10010 ; j++){
        if(a[j] < a[j + 1]){
            a[j] = a[j + 1];
        }
        else if(a[j] = a[j]){
            a[j] = a[j];
        }
        else if{
            break;
        }
    }
    cout << a;


    fclose(stdin);
    fclose(stdout);
    return 0;
}
