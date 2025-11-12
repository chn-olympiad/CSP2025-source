#include <bits/stdc++.h>
#include <string>
using namespace std;
bool cmp(int x,int y){
    x > y;
}
int main(){
    string s,j;
    cin >> s;
    int k = s.length();
    for(int i = 0;i < k;i++){
        if(s[i] >= '0' && s[i] <= '9')
            j[i] == s[i];
        else
            continue;
    }
    int l = j.length();
    sort(j[0],j[l],cmp);
    cout << j;
    return 0;
}
