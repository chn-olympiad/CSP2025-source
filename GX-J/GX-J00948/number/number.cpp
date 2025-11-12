#include<bits/stdc++.h>
using namespace std;
int tong[9];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        int t=0;
        if(s[i]>='0'&&s[i]<='9'){
            t=int(s[i]-='0');
            tong[t]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=tong[i];j++) cout<<i;
    }
    return 0;
}
