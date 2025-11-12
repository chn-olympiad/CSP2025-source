#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],k;
int main(){
    freopen("number1.in","r",stdin);
    freopen("number1.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(int(s[i]-'0')>=0&&int(s[i]-'0')<=9){
            k++;
            a[k]=int(s[i]-'0');
        }
    }
    sort(a+1,a+k+1);
    for(int i=k;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
