#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int N = 500010;
int nums[N];
string TenToTwo(int a){
    string s = "", res = "";
    while(a != 0){
        int y = a % 2;
        s += to_string(y);
        a /= 2;
    }
    for(int i = s.size()-1; i >= 0; i --) res += s[i];
    return res;
}
int TwoToTen(string s){
    int res = 0, val = 0;
    for(int i = s.size()-1; i >= 0; i ++){
        res += int(s[i]) * pow(2,val);
    }
    return res;
}
int xor_(string s1, string s2){
    int l = max(s1.size(), s2.size());
    int a[2][l];
    memset(a,0,sizeof a);
    int l1 = l, l2 = l;
    string st = "";
    for(int i = s1.size()-1; i >= 0; i ++) a[0][l1-1] == s1[i];
    for(int i = s2.size()-1; i >= 0; i ++) a[0][l2-1] == s2[i];
    for(int i = 0; i < l; i ++){
        if(a[0][i] == a[1][i]) st += "0";
        else st += "1";
    }
    return TwoToTen(st);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    std::cout << "i_cant_do_this_uwu";
    return 0;
}
