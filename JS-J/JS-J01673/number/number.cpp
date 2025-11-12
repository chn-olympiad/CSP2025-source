#include<bits/stdc++.h>
using namespace std;
string s;
int n,k;
map<int,int> mp;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    s=' '+s;
    for(int i=1;i<=n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            mp[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(mp[i]&&i!=0)k=1;
        if(i==0&&k==0){
            cout<<"0";
            return 0;
        }
        while(mp[i]){
            cout<<i;
            mp[i]--;
        }
    }
    return 0;
}
