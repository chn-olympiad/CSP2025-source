#include<bits/stdc++.h>
using namespace std;

int n[10] = {0};

int main(){
    string a;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> a;
    for(int i=0;i<a.size();i++){
        if('0' <= a[i] && a[i]<='9'){
            n[a[i]-'0']++;
        }
    }
    for(int i=9;i>=1;i--){
        char ans = i;
        if(n[i]!=0){
             cout << n[i] * i;
        }
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
