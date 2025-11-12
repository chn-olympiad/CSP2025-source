#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","r",stdout);
    
    char s[10005];
    char a[10005];
    for(int i=1;i<=10005;i++){
        cin >> s[i];
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i];
        }
    }
    for(int i=1;i<=10005;i++){
        if(a[i]>=a[i+1]){
            cout << a[i];
        }
        else{
            cout << a[i+1];
        }
    }
    return 0;
}
