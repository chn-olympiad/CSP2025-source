#include<bits/stdc++.h>
using namespace std;
int a[1000010]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int t=0;
    for(int i=0;i<s.length();i++){
        if(s[i]>='a'&&s[i]<='z'){
            continue;
        }
        else{
            a[t++]=s[i]-'0';
        }
    }
    sort(a,a+t);
    for(int i=t-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
