#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='9')  cout<<9;
        else if(s[i]>='0'&&s[i]<='8')  a[s[i]-'0']++;
    }
    for(int i=8;i>=0;i--){
        while(a[i]--)  cout<<i;
    }return 0;
}
