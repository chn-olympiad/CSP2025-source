#include<bits/stdc++.h>
using namespace std;
string s;
vector<char>v;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    for(auto i:s){
        if('0'<=i&&i<='9')v.push_back(i);
    }
    sort(v.begin(),v.end(),cmp);
    for(auto i:v)cout<<i; 
}
