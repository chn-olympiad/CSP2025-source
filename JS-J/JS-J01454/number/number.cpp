#include <bits/stdc++.h>
using namespace std;
char c;
int a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(c = getchar(),c!='\n')
        if('0'<=c&&c<='9') a[c-'0']++;
    for(int i= 9;i>=0;i--)
        while(a[i]--)cout<<i;
    return 0;
}
