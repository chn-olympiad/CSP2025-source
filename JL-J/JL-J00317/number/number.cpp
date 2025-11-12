#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
string s;
int a[100009];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i];
        }
    }
    sort(a,a+s.size()+1,cmp);
    for(int i=0;i<s.size();i++){
        if(a[i]==0){
            continue;
        }
        else{
            cout << char(a[i]);
        }
    }
    return 0;
}
