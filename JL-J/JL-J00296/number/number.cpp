#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48&&s[i]<=57){
            a[i]=s[i];

        }

    }
    sort(a,a+s.size(),cmp);
    for(int i=0;i<=s.size();i++){
        if(a[i]!=0){
            cout<<a[i]-48;
        }
    }

    return 0;
}
