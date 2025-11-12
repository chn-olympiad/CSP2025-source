#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
    return x>y;
}
int main(){
    fopen("number.in","r");
    fopen("number.out","w");

    string s;
    cin>>s;
    sort(s.begin(),s.end(),cmp);
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9')cout<<s[i];
    }
    return 0;
}
