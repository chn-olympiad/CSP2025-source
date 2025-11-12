#include<bits/stdc++.h>
using namespace std;
string s;
long long num[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    for(long long i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(long long j=num[i];j>0;j--){
            cout<<i;
        }
    }
    cout<<endl;
    return 0;
}
