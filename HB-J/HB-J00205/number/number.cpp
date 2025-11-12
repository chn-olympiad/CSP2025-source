#include<bits/stdc++.h>
using namespace std;
char n;
long long a[9];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>n){
        if(n>='0'&&n<='8'){
            a[n-48]++;
        }
        if(n=='9')cout<<9;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++)cout<<i;
    }
    return 0;
}
//luogu:1073546
//rp++
