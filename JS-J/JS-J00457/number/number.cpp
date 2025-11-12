#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s;
int a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i = 0;i < s.size();i++)
        if(isdigit(s[i])) a[s[i] - '0']++;
    for(int i = 9;i >= 0;i--){
        for(int j = 0;j < a[i];j++){
            cout<<(char)(i + '0');
        }
    }
    return 0;
}
