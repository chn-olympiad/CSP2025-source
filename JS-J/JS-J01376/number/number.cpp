#include<bits/stdc++.h>
#define ll long long
using namespace std;
string str;
ll a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]>='0'&&str[i]<='9'){
            a[str[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++) cout<<i;
    }
    cout<<'\n';
    return 0;
}