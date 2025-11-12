#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int len,t,a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[++t]=s[i]-'0';
        }
    }
    sort(a+1,a+t+1);
    if(a[t]==0)cout<<0;
    else{
        for(int i=t;i>=1;i--)printf("%d",a[i]);
    }
    return 0;
}
