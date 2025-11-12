#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int> n;
    for(int i = 0;i<s.size();i++){
        if('0'<=s[i] && s[i]<='9'){
            n.push_back(s[i]-'0');
        }
    }
    sort(n.begin(),n.end(),cmp);
    for(int i:n){
        cout<<i;
    }
    fclose(stdin);
    fclose(stdout);
	return 0;
}
