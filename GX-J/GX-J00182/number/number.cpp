#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long t[15];
    cin >> s;

    long long len = s.size();
    for(int i=0;i<=len;i++){
        if(s[i]==0 || s[i]==1 || s[i]==2 || s[i]==3 || s[i]==4 || s[i]==5 || s[i]==6 || s[i]==7 || s[i]==8 || s[i]==9){
            t[s[i]]++;
        }
    }

    for(int i=len;i>=0;i++){
        for(int j=1;j<=t[i];i++){
            if(t[i]!=0){
                cout << i;
            }
        }
    }
    return 0;
}
