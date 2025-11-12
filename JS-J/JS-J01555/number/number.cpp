#include <bits/stdc++.h>
using namespace std;
int p[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin >> a;
    int len=a.size();
    for(int i = 0;i<len;i++){
        if(a[i]>='0'&&a[i]<='9'){
            p[a[i]-'0']++;
        }
    }
    for(int i = 9;i>=0;i--){
        for(int j = 0;j<p[i];j++){
            cout << i;
        }
    }
    cout << endl;
    return 0;
}
