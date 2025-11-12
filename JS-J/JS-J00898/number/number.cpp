#include<bits/stdc++.h>
using namespace std;
long long n,a[1000010],cnt;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9') a[++cnt]=int(s[i]-48);
    }
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>=1;i--) cout<<a[i];
    return 0;
}
