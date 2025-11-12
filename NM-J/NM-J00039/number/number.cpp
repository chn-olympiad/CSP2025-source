#include<iostream>
#include<string>
using namespace std;
string s;
long long t[1000]={},c=0;
bool ans(int a,int b){
    return a>b;
}
int main(){
    freopen("numder.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.rought();i++){
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
            t[c]==s[i];
            c++;
        }
    }
    sort(t,t+c-1,ans)
    for(int i=0;i<=c-1;i++){
        cout<<t[i];
    }
    return 0;
}

