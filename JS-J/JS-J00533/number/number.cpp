#include<bits/stdc++.h>
using namespace std;
long a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;

    for(long i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }bool hl=1;
    for(long i=9;i>=0;i--){
        if(i==0&&hl==1){
            cout<<0;
            return 0;
        }
        for(long j=a[i];j>=1;j--){
            cout<<i;
            hl=0;
        }
    }
    return 0;
}
