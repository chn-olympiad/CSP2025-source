#include<bits/stdc++.h>
using namespace std;
string s;
int h[15];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){

        if('0'<=s[i]&&s[i]<='9'){
            int x=s[i]-'0';
            h[x]++;
        }
    }
    for(int i=9;i>=0;i--){
        if(h[i]){
            for(int j=1;j<=h[i];j++){cout<<i;}
        }
    }
    cout<<endl;
    return 0;
}
