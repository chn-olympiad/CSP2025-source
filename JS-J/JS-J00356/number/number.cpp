#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int s[10]={0,0,0,0,0,0,0,0,0,0},ite=0;
int main(){
    freopen("number.in","w",stdin);
    freopen("number.out","r",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a;
    cin >> a;
    for(int i=0;i<a.size();i++){
        if(0+a[i]>=48 && 0+a[i]<=57){
            s[0+a[i]-48]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<s[i];j++){
            cout << i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
