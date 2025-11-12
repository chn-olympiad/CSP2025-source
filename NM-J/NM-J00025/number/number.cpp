#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[11];
    int te;
    string s;
    cin>>s;
    for(int i=0;i<=s.size();i++){
        int b=s[i];
        if(b>='0'&&b<='9'){
            a[b]++;
        }
    }
    for(int i=9;i>=0;i--){
        if(a[i]==0){
            continue;
        }else{
            cout<<i;
            a[i]--;
        }
    }
    return 0;
}
