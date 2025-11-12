#include <bits/stdc++.h>
using namespace std;
string s;
int maxn[10000];
int a=0,b=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'){
            maxn[b]=s[i];
            b++;
        }else{
            a++;
        }
    }
    for(int i=0;i<s.length()-a-1;i++){
        for(int j=0;j<s.length()-a-i-1;j++){
            if(maxn[j]<maxn[j+1]){
                swap(maxn[j],maxn[j+1]);
            }
        }
    }
    for(int i=0;i<s.length()-a;i++){
        cout << maxn[i]-'0';
    }
    return 0;
}
