#include<bits/stdc++.h>
using namespace std;
freopen("number.in","r",stdin);
freclose("number.out","w",stdout);
string s;

int cnt,a[1000005];


int main(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[cnt]=s[i]-'0';
            cnt++;
        }
    }
    sort (a,a+cnt);
    for(int i=cnt-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
