#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<char>A;
    for(int i=0;i<s.length();i++)if(s[i]>='0'&&s[i]<='9')A.push_back(s[i]);
    sort(A.begin(),A.end());
    if(A[A.size()-1]=='0')cout<<0;
    else for(int i=1;i<=A.size();i++)cout<<A[A.size()-i];
    return 0;
}