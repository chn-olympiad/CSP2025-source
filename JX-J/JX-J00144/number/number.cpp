#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>> s;
    int n=1;
    char a[10005];
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[n]=s[i];
            n++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            if(a[j]>a[j+1])swap(a[j],a[j+1]);
        }
    }
    for(int i=n;i>=1;i--){
        cout << a[i];
    }
    return 0;
}
