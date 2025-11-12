#include <bits/stdc++.h>
using namespace std;
int n[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for (int i=1;i<=1000005;i++){
        for (int j=0;j<=9;j++)if (s[i]=j)n[j]+=1;
    }
    for (int i=0;i<=9;i++){
        for (int j=1;j<=n[i];j++)cout<<i;
    }
    return 0;
}
