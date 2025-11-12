#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
bool cmp(int a,int b){
    return b>a;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9' && s[i]>='0'){
            int number=s[i]-'0';
            v.push_back(number);
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i];
    }
	return 0;
}
