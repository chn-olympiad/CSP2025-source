#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long sns[1000005];
    cin>>s;
    int len1=s.size(),len2=0;
    for(int i=0;i<len1;i++){
        if(s[i]>='0' && s[i]<='9'){
            sns[i]+=s[i]-'0';
            len2++;
        }
    }
    sort(sns,sns+len2+1,cmp);
    for(int i=0;i<len2;i++){
        cout<<sns[i];
    }
    return 0;
}
