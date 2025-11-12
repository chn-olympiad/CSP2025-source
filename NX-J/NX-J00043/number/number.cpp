#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005]={0},b=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[b]=s[i]-'0';
            b++;
        }
    }
    sort(a+1,a+1+b);
    for(int i=b;i>1;i--){
        cout<<a[i];
    }
    return 0;
}
