#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 +10;
int l[N] = {0};

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int a=s.size(), b = 0;
    for(int i = 0; i < a; i++){
        if(s[i] == '9'){
            l[b] = s[i] -'0';
            b++;
        }
        else if(s[i] == '8'){
            l[b] = s[i] -'0';
            b++;
        }
        else if(s[i] == '9'){
            l[b] = s[i] -'0';
            b++;
        }
        else if(s[i] == '7'){
            l[b] = s[i] -'0';
            b++;
        }
        else if(s[i] == '6'){
            l[b] = s[i] -'0';
            b++;
        }
        else if(s[i] == '5'){
            l[b] = s[i] -'0';
            b++;
        }
        else if(s[i] == '4'){
            l[b] = s[i] -'0';
            b++;
        }
        else if(s[i] == '3'){
            l[b] = s[i] -'0';
            b++;
        }
        else if(s[i] == '2'){
            l[b] = s[i] -'0';
            b++;
        }
        else if(s[i] == '1'){
            l[b] = s[i] -'0';
            b++;
        }
        else if(s[i] == '0'){
            l[b] = s[i] -'0';
            b++;
        }
    }
    sort(l,l+b);
    for(int i = b-1; i >= 0; i--){
        cout << l[i];
    }
    return 0;
}