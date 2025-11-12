#include<iostream>
using namespace std;
int n[13];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i = 0;i < a.length();i++){
        if(a[i] >= '0' && a[i] <= '9'){
            n[a[i]-'0']++;
        }
    }
    for(int i = 9;i >= 0;i--){
        if(n[i] == 0) continue;
        for(int j = 1;j <= n[i];j++){
            cout<<i;
        }
    }
}
