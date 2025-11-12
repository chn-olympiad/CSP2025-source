#include<bits/stdc++.h>
using namespace std;
int ans = 0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n = s.size();
    int num[n];
    for(int i = 0;i<s.size();i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            num[i]  = s[i]-'0';
        }else{
            ans++;
        }
    }
    sort(num,num+s.size());
    for(int i = s.size()-1;i>=ans;i--){
         cout<<num[i];
    }
}
