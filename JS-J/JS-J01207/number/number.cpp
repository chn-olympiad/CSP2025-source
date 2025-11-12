#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] >= 48 && s[i] <= 57){
            a[cnt] = s[i] - 48;
            cnt++;
        }
    }
    sort(a,a + cnt,cmp);
    if(a[0] == 0){
        cout << 0;
    }
    else{
        for(int i = 0;i < cnt;i++){
            cout << a[i];
        }
    }
    return 0;
}
