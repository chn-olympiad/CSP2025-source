#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s1;cin>>s1;
    int cnt=0;
    for(int i=0;i<s1.size();i++){
        if(isdigit(s1[i])){
            a[s1[i]-'0']++;
            cnt++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
