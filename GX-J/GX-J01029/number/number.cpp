#include <bits/stdc++.h>
using namespace std;
string s,a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a+=s[i];
        }
    }
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            if(a[i]<a[j])
                swap(a[i],a[j]);
        }
    }
    for(int i=0;i<a.size();i++){
        cout<<(a[i]-'0');
    }
    return 0;
}
