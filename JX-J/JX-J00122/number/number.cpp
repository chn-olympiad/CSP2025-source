#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],n;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'<=9&&s[i]-'0'>=0){
            a[s[i]-'0']++;
            if(s[i]!='0'){
                n=1;
            }
        }
    }
    if(n==0){
        cout<<n;
    }else{
        for(int i=9;i>=0;i--){
            if(a[i]!=0){
                while(a[i]--){
                    cout<<i;
                }
            }
        }
    }
    return 0;
}
