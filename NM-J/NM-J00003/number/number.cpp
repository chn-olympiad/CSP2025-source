#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string s;
int len,a[10005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;
    len = s.size();
    for(int i=0;i<len;i++){
       if('0'<=s[i]<='9'){
            a[s[i] - '0']++;
       }
    }

    for(int i = 9;i>=0;i--){
        for(int j=a[i];j>0;j--){
            cout<<i;
        }
    }

    return 0;
}
