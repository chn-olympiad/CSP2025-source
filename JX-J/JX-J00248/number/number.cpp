#include<bits/stdc++.h>
using namespace std;
vector<int> data;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]-'9'<=0 and s[i]-'0'>=0){
            int x=s[i]-'0';
            data.push_back(x);
        }
    }
    sort(data.begin(),data.end());
    for(int i=data.size()-1;i>=0;i--){
        cout<<data[i];
    }
    return 0;
}
