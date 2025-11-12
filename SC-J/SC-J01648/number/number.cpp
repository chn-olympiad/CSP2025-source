#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int a[10]={0};
    for(int i=0;i<s.size();i++){
        int m=int(s[i]-'0');
        if(m<=9&&m>=0){
            a[m]++;
        }
    }
    for(int i=9;i>=0;i--){
        while(a[i]!=0){
            cout << i;
            a[i]--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}