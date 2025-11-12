#include<bits/stdc++.h>
using namespace std;
int numm[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'<=9){
            numm[s[i]-'0']++;
        }
    }
    for(int i=10;i>=0;i--){
        while(numm[i]){
            cout<<i;
            numm[i]--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
