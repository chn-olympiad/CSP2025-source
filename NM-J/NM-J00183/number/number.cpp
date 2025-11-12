#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
string f[N];
bool cmp(string a,string b){
    return a + b > b + a;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a = 0;
    for(int i = 0;i < s.size();i ++){
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
            f[a] = s[i];
            a++;
        }
    }
    sort(f,f+a,cmp);
    for(int i = 0;i < a;i ++){
        cout<<f[i];
    }
    return 0;
}
