#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int dex=1;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[dex]=s[i]-'0';
            dex++;
        }
    }
    dex--;
    sort(a+1,a+dex+1);
    for(int i=dex;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
