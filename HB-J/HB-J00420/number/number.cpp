#include<bits/stdc++.h>
using namespace std;
string s;
long long p=0,a[2000001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            p++;
            a[p]=s[i]-'0';
        }
    }
    sort(a+1,a+p+1);
    for(int i=p;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
