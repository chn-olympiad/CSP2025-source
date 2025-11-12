#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int a[10];
    memset(a,0,sizeof(a));
    for(int i=0;i<s.size();i++){
        if(s[i] <= '9' && s[i] >= '0') a[(int)(s[i] - '0')]++;
    }
    string c;
    int j=0;
    for(int i=0;i<=9;i++){
        while(a[i]--){
            c[j++] = (char)(i + '0');
        }
    }
    for(int i=j-1;i>=0;i--){
        cout << c[i];
    }
    return 0;
}
