#include <bits/stdc++.h>
using namespace std;
int d[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int h=0;
    int big=0;
    cin>>s;
    for(int i=0;i<10000;i++){
        if(s[i]-'0'>=0&&s[i]+'0'<=9){
            h++;
            d[h]=s[i]-'0';
        }
    }
    int q=h/2+h%2;
    for(int i=0;i<=h;i++){
        cout<<d[h]<<" ";
    }
return 0;
}
