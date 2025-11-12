#include<bits/stdc++.h>
using namespace std;
int a[1000009],l=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    for(int i = 0;i<s.size();i++){
        if(int(s[i])<65){
            a[l]=int(s[i])-48;
            l++;
        }
    }
    sort(a,a+l);
    for(int i = l-1;i>=0;i--){
        cout << a[i];
    }
    return 0;
}
