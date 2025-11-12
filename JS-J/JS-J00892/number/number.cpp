#include<bits/stdc++.h>
using namespace std;
static bool cmp(char& a,char& b){
    return a > b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    string str; cin >> str;
    string cnt;
    for(char it:str){
        if(it >= '0'&&it <= '9'){
            cnt+=it;
        }
    }
    sort(cnt.begin(),cnt.end(),cmp);
    cout << cnt;
    return 0;
}
