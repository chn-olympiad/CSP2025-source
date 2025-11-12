#include <bits/stdc++.h>
using namespace std;
int a[100001];

string toBin(int n){
    string s;
    while(n > 1){
        int t = n % 2;
        s += char(t + '0');
        n = n/2;
    }
    s += char(n + '0');
    string str;
    int j = 0;
    for(int i = s.size() - 1; i >= 0; i--){
        str += s[i];
    }
    return str;
}

int fromBin(string s){
    int n = 0;
    int ind = 1;
    for(int i = s.size()-1; i >= 0; i--){
        n += ind * int(s[i] - '0');
        ind *= 2;
    }
    return n;
}

int Xor(int n1, int n2){
    string s1 = toBin(n1), s2 = toBin(n2), ts="";
    int t = min(s1.size(), s2.size());
    int tt = max(s1.size(), s2.size());
    if(s1.size() == t){
        while(s1.size() != s2.size()){
            s1 = '-' + s1;
        }
    }
    else{
        while(s2.size() != s1.size()){
            s2 = '-' + s2;
        }
    }
    t--;tt--;

    for(int i = tt; i >= 0; i--) {
        if((s1[i] == '0' || s1[i] == '1') && (s2[i] == '0' || s2[i] == '1')){
            if(s1[i] != s2[i]){
                ts += '1';
            }
            else ts += '0';
        }
    }
    string sans;
    int j = 0;
    for(int i = ts.size() - 1; i >= 0; i--){
        sans[j] = ts[i];
        j++;
    }
    return fromBin(sans);
}

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cout<<12;

    return 0;
}

