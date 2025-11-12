#include<bits/stdc++.h>
using namespace std;
vector<int> se;
int main(){
    freopen("number.in" , "r" , stdin);
   freopen("number.out" , "w" , stdout);
    string s;
    cin.tie(0)->sync_with_stdio(0);
    cin >>s;
    for(int i=0 ; i <s.size();i++){
        if(isdigit(s[i])){
            se.push_back(s[i] - '0');
        }
    }
    sort(se.begin() , se.end() , [](int a , int b){return a >b;});
    for(int x : se){
        cout << x;
    }
}

