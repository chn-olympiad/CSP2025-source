#include<bits/stdc++.h>
using namespace std;
string s;
long long a[9];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(a[i]>0){
            for(int j=a[i];j>0;j--){
                cout<<char(i+'0');
            }
        }
    }
    return 0;
}
