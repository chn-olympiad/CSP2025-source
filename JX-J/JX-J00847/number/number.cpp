#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.ans","w",stdout);
    cin>>s;
    for(int i=0;i<=s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=(int)s[i];
        }
    }
    sort(a+0,a+s.length());
    for(int i=s.length()-1;i>=0;i--){
        cout<<(char)a[i];
    }
    return 0;
}
