#include<bits/stdc++.h>
using namespace std;
string s,t;
long long a[1000015];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[i+1]=s[i]-48;
        }
        else{
            a[i+1]=-1;
        }
    }
    sort(a+1,a+s.size()+1);
    for(int i=s.size();i>=1;i--){
        if(a[i]!=-1){
            cout<<a[i];
        }
    }
    return 0;
}
