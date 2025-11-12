#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s;
int m = 0,w = 0;
int cmp(int a,int b){
    return a > b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i < s.size();i++){
        if((s[i]-'0')<=9&&(s[i]-'0')>=0){
            m = m*10+s[i]-'0';
            w++;
        }
    }
    int t[N];
    t[0] = m%10;
    for(int i = 1;i <= w;i++){
        m = m/10;
        t[i] = m%10;
    }
    sort(t,t+w+1,cmp);
    for(int i = 0;i < w;i++){
        cout << t[i];
    }
    return 0;
}
