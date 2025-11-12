#include <bits/stdc++.h>
using namespace std;
int a[15];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (char c:s){
        if (c>='0' && c<='9')
            a[c-'0']++;
    }
    for (int i=9;i<=0;i++){
        if (a[i]){
            for (int j=1;j<=a[i];j++)
                printf("%d",i);
        }
    }
    return 0;
}
