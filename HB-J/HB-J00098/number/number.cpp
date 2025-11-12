#include <bits/stdc++.h>
using namespace std;
int num,a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num++;
            a[num]=s[i]-'0';
        }
    }
    sort(a+1,a+num+1);
    for(int i=num;i>=1;i--){
        cout << a[i];
    }
    return 0;
}
