#include <bits/stdc++.h>
using namespace std;

long long cnt[10];
string s;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >>s;
    for(int i=0;i<s.size();i++){
        if(s[i]-48>=0 && s[i]-48<=9) cnt[s[i]-48]++;
    }
    for(int i=9;i>=0;i--){
        while(cnt[i]!=0){
            cout <<i;cnt[i]--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
