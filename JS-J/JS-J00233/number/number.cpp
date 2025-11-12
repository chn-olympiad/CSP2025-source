#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    vector<int> v;
    for(char c:s){
        int i = c-'0';
        if(i<=9 && i>=0){
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(int i:v){
        cout<<i;
    }


    return 0;
}