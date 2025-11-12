#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int cnt = 0;
bool tmp(int x,int y){
    return x > y;
}
int main(){
        freopen("number.in","r",stdin);
        freopen("number.out","w",stdout);
        cin >> s;
        for(int i = 0;i < s.size();i++){
            if(!(s[i] >= 97)){
                a[cnt] = s[i] - '0';
                cnt++;
            }
        }
        sort(a,a+cnt,tmp);
        for(int i = 0;i < cnt;i++){
            cout << a[i];
        }
        fclose(stdin);
        fclose(stdout);
        return 0;
}
