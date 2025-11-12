#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<=9;j++){
            if(s[i]==j)
                a[i]=s[i];
        }
    }
    for(int i=0;i<s.size();i++){
        sort(a,a+s.size());
    }
    for(int i=0;i<s.size();i++){
        cout<<a[i];
    }
    return 0;
}
