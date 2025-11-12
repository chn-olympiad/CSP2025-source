#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int bk[100010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]<='9') bk[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        if(bk[i]!=0){
            for(int j=0;j<bk[i];j++) cout<<i;
        }
    }



    return 0;
}
