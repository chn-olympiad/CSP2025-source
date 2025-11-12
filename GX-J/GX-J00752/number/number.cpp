#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    vector<int> a(0);
    for (int i=0; i<s.size(); i++){
        if (s[i]>='0' && s[i]<='9'){
            a.push_back(s[i]-'0');
        }
    }
    sort(a.begin(),a.end());
    for (int j=a.size()-1; j>=0; j--){
        cout << a[j];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
