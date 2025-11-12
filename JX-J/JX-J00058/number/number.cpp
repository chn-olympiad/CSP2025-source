#include<bits/stdc++.h>
using namespace std;
string s;
int t[128];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i=0;i<s.length();i++) if(s[i]>='0'&&s[i]<='9') t[s[i]]++;
    int a=0;
    for(int i='9';i>='0';i--){
        if(t[i]!=0&&i!='0')a=1;
        for(int j=1;j<=t[i];j++){
            if(i!='0'||a==1) putchar(i);
            else
            {
                cout << '0';return 0;
            }
        }
    }
    return 0;
}
