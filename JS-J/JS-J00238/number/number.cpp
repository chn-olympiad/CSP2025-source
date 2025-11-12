#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
map <int,int> mp;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            mp[int(s[i]-48)]++;
        }
    }
  //  cout<<"\n";
    for(int i=9;i>=0;i--){
        for(int j=1;j<=mp[i];j++) cout<<i;
    }
    return 0;
}