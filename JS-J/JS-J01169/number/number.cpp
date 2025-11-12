#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int n,top,a[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    s=" "+s;
    for(int i=1;i<=n;i++){
        if('0'<=s[i]&&s[i]<='9')a[++top]=s[i]-'0';
    }
    sort(a+1,a+top+1);
    if(a[top]==0){
        cout<<0;
        return 0;
    }
    for(int i=top;i>=1;i--)cout<<a[i];
    return 0;
}
