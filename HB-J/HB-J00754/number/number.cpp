#include<bits/stdc++.h>
using namespace std;
long long a[1000000],x;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
long long num=1,ans=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        a[i]=-1;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'>=0&&s[i]-'0'<=9){
            ans++;
            num=num*10;
            a[i]=s[i]-'0';
        }
    }
    sort(a,a+s.size());
    for(int i=s.size();i>=s.size()-ans;i--){
        x+=a[i]*num;
        num=num/10;
    }
    cout<<x;
    return 0;
}
