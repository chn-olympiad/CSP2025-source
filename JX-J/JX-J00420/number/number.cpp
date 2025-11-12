#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[1000010],cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[cnt++]=s[i]-'0';
        }
    }
    sort(a,a+cnt);cnt--;
    for(;cnt>=0;cnt--){
        cout<<a[cnt];
    }
    return 0;
}