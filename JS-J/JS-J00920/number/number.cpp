#include<bits/stdc++.h>
using namespace std;
long long a[10005],k;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[k]=s[i]-'0';
            k++;
        }
    }
    sort(a,a+k);
    if(a[k-1]==0){
        cout<<0;
        return 0;
    }
    for(int i=k-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
