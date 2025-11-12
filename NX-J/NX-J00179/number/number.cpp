#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000010],n;
bool cmp(int a,int b){ return a > b; }
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str; cin >> str;
    if(str.size() == 1) return cout << str,0;
    for(int i = 0;i < str.size();i++)
        if(isdigit(str[i])) a[++n] = str[i] - '0';
    sort(a+1,a+n+1,cmp);
    for(int i = 1;i <= n;i++) cout << a[i];
    return 0;
}
