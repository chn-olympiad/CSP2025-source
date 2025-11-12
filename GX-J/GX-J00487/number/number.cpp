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
    int num[s.length()+10],jsq=0;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9') num[jsq++]=s[i]-'0';
    }
    sort(num,num+jsq,cmp);
    for(int i=0;i<jsq;i++){
        cout<<num[i];
    }
    cout<<endl;
    return 0;
}
