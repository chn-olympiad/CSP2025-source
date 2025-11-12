#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[cnt++]=(s[i]-'0');
        }
    }
    sort(a,a+cnt);
    if(a[cnt-1]==0){
        cout<<0;
        return 0;
    }
    for(int i=cnt-1;i>=0;i--)cout<<a[i];
    return 0;
}
