#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[s.size()+10]={0},t=1;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            int l=s[i]-'0';
            a[t++]=l;
        }
    }
    t--;
    sort(a+1,a+t+1);
    for(int i=t;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
