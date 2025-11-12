#include<bits/stdc++.h>
using namespace std;
int num[20];
string s;
char c;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        c=s[i];
        if('0'<=c and c<='9'){
            num[c-48]++;
        }
    }

    for(int i=9;i>=0;i--){
        while(num[i]){
            cout<<i;
            num[i]--;
        }
    }
    return 0;
}
//99998888887777766666655555544444433332111000000000
//99998888887777766666655555544444433332111000000000
//999
