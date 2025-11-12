#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    string t="";
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            t+=s[i];
        }
    }
    int a[1000005]={0};
    for(int i=0;i<t.size();i++){
        a[i]=t[i]-'0';
    }
    sort(a,a+t.size(),cmp);
    for(int i=0;i<t.size();i++){
        cout<<a[i];
    }
    return 0;
}
