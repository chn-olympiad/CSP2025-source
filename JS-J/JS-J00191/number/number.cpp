#include <bits/stdc++.h>
using namespace std;

string s;
long long a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    for (int i=0;i<10;i++)
        a[i]=0;
    for (int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
            a[s[i]-'0']++;
    }
    for (int i=9;i>=0;i--){
        for (int j=1;j<=a[i];j++)
            cout << i;
    }
    return 0;
}