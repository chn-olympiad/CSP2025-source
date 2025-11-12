#include <bits/stdc++.h>
using namespace std;
string s;
int a[20];
int main(){
    freopen("number.in","r",stdin);        freopen("number.out","w",stdout);
    cin>>s;
    for (int i=0;i<s.size();i++){
        if (s[i]<='9'&&s[i]>='0') a[s[i]-'0']+=1;
    }
    int b=1;
    for (int i=9;i>=0;i--){
        while (a[i]!=0){
            cout<<i;
            a[i]-=1;
            if (b&&i==0) return 0;
            else b=0;
        }
    }
    fclose(stdin);      fclose(stdout);
    return 0;
}