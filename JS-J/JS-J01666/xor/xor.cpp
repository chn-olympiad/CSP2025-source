#include<bits/stdc++.h>
using namespace std;
long long n , k , a[1000005];
long long to_ll(string s){
    long long res = 0;
    for(int i = s.size()-1;i >= 0;i--){
        res *= 10;
        res += s[i] - '0';
    }
    return res;
}
long long ten_to_two(long long x){
    string s;
    while(x > 0){
        string s1 = to_string(x%2);
        s = s + s1;
        x /= 2;
    }
    return to_ll(s);
}
long long _xor(long long x,long long y){
    string s1 = to_string(x) , s2 = to_string(y);
    string s;
    if(s1.size() > s2.size()){
        while(s2.size() != s1.size())s2 = "0" + s2;
    }
    if(s1.size() < s2.size()){
        while(s2.size() != s1.size())s1 = "0" + s1;
    }
    for(int i = 0;i < s1.size();i++){
        if(s1[i] != s2[i])s = "1" + s;
        else {
            s = "0" + s;
        }
    }
    return to_ll(s);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int res = 0;
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i]==k){
                a[i] = -1;
                res++;
        }
        else a[i] = ten_to_two(a[i]);
    }
    k = ten_to_two(k);
    for(int i = 1;i <= n;i++){
            long long f;
        for(int j = i;j <= n;j++){
            if(a[j] == -1)break;
            if(i==j)f = a[i];
            else{
                f = _xor(f,a[j]);
            }
            if(_xor(f,k) == 0){
                res++;
                for(int m = i;m <= j;m++)a[m] = -1;
                break;
            }
        }
    }
    cout << res;
    return 0;
}
