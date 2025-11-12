#include <bits/stdc++.h>
using namespace std;
char c;
int a[10],l;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>c){
        if(c>='0'&&c<='9'){
            a[c-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(a[i]){
            for(int j=1;j<=a[i];j++){
                cout<<i;
            }
        }
    }
    return 0;
}
