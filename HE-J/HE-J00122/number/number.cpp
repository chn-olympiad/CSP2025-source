#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int main(){string a;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>a;
    int d=0;
    int b[1000000]={};
    for(int i=0;i<a.length();i++){
        if (a[i]>='0'&&a[i]<='9'){
            b[d]=int(a[i])-48;
            d++;
        }
    }
    sort(b,b+d);
    reverse(b,b+d);
    for(int i=0;i<d;i++){
        cout<<b[i];
    }
    return 0;}



