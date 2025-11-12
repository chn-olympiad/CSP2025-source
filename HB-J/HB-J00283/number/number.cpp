#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[1000003],b=0;
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        if(s[i]>='0' && s[i]<='9'){
            a[i]=s[i]-'0';
            b+=1;
        }
    }
    sort(a,a+b);
    for (int i = b-1; i >= 0; i--){
        cout << a[i];
    }
    cout << endl;
    return 0;
}