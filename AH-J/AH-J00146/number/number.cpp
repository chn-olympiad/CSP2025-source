#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int> num;
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]>='0' && s[i]<='9'){
            int k=s[i]-'0';
            num.push_back(k);
        }
    }
    sort(num.begin(),num.end());
    int l=num.size();
    for(int i=l-1;i>=0;i--){
        cout<<num[i];
    }
    return 0;
}
