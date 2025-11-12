#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string s;
bool b[305];
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
        }else{
            s.erase(i,1);
            i--;
        }
    }
    sort(s.begin(),s.end(),cmp);
    while(s.size()!=1&&s[0]=='0'){
        s.erase(0,1);
    }
    cout<<s;
    return 0;
}

