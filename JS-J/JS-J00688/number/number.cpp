#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010],l,n;
string s;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            n++;
            a[n]=s[i]-'0';
        }
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
