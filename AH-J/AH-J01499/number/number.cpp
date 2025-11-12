#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int numder = 0;
    int ass;
    int a[1000000];
    cin >> s;
    for(int i = 0;i < s.length();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            a[i] = s[i] - '0';
            numder++;
        }
    }
    for(int i = 0;i < numder;i++){
        for(int j = i;j > 0;j--){
            if(a[j] >= a[j-1]){
                ass = a[j];
                a[j] = a[j-1];
                a[j-1] = ass;
            }
        }
    }
    for(int i = 0;i < numder;i++){
        cout << a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

