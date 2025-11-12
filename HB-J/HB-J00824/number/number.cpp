#include<bits/stdc++.h>
using namespace std;
string s;
int a[15],len;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    len=s.size();
    for(int i=0;i<len;i++){
        char c=s[i];
        if('0'<=c<='9')a[c-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++)cout<<i;
    }
    return 0;
}
