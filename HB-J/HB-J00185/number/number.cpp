#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int k[1000006],r=0;
    cin>>s;
    for(int i=0;i<=s.size();i++){
        int op=s[i]-'0';
        if(0<=op&&op<=9){
            k[r]=op;
            r++;
        }
    }
    sort(k,k+r);
    for(int i=r-1;i>=0;i--) cout<<k[i];
    return 0;
}
