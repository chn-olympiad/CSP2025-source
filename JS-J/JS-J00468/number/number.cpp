#include<bits/stdc++.h>
using namespace std;
string s;
char a[100101];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
            a[i]=s[i];
    }
    sort(a,a+n);
    for(int i=n;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
