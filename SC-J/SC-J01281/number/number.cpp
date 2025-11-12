#include<bits/stdc++.h>
using namespace std;
string s;
int i,a[1000010],k=0;
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    cin>>s;
    if(s.size()==1){
        cout<<s;
        return 0;
    }
    for(i=1;i<=s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
          a[++k]=s[i]-'0';
        }
    }
    sort(a+1,a+k+1);
    for(i=k;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
