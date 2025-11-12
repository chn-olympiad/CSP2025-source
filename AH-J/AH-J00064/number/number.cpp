#include <bits/stdc++.h>
using namespace std;
const int N = 10;
string str;
long long len;
long long t[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    len = str.size();
    for(long long i = 0;i<len;i++){
        if(str[i] <= '9' && str[i] >= '0'){
            t[str[i]-'0']++;
        }
    }
    for(long long i = 9;i>=0;i--){
        if(t[i] != 0){
            while(t[i] != 0){
                cout<<i;
                t[i]--;
            }
        }
    }


    return 0;
}
