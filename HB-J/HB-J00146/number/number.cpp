#include<bits/stdc++.h>
using namespace std;
string a;
int nu[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> a;
    for(int i= 0;i<=a.size();i++){
        if(a[i]-'0'>=0&&a[i]-'0'<=9)nu[a[i]-'0']+=1;
    }
    for(int i = 9;i>=0;i--){
        while(nu[i]!=0){
            cout << i;
            nu[i]--;
        }
    }
    return 0;
}
