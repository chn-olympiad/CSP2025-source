#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int a,int b){
	return a>b;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    vector<int> number;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
            number.push_back(s[i]-'0');
    }
    sort(number.begin(),number.end(),cmp);
    for(int i=0;i<number.size();i++){
        cout<<number[i];
    }
    return 0 
}
