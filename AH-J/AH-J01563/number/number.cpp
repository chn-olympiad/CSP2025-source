#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    sort(s.begin(),s.end(),cmp);
    bool flag=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='1'&&s[i]<='9'){
            flag=1;
        }
    }
    if(!flag){
        cout<<0;
        return 0;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            cout<<s[i];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
