#include<bits/stdc++.h>
using namespace std;
string s;
int a[114514],sum;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9' and s[i]>='0') a[++sum]=s[i]-'0';
    }
    sort(a+1,a+1+sum);
    for(int i=sum;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
