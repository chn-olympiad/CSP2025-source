#include<iostream>
#include<algorithm>
#include<string>
char c[100001];
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,nums;
    cin>>s;
    for(int j=0;j<s.length();j++){
        if(s[j]=='0'||s[j]=='1'||s[j]=='2'||s[j]=='3'||s[j]=='4'||s[j]=='5'||s[j]=='6'||s[j]=='7'||s[j]=='8'||s[j]=='9'){
            nums+=s[j];
        }
    }
    sort(nums.rbegin(),nums.rend());
    cout<<nums<<endl;
}

