#include<bits/stdc++.h>
using namespace std;
char n[1000005];
int a[1000005],cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)n[i]=s[i];
    sort(n,n+s.size());
    for(int i=0;i<s.size();i++){
        if(n[i]<='9'&&n[i]>='0'){
a[i]=n[i]-'0';
cnt++;
        }
    }
    for(int i=cnt-1;i>=0;i--)cout<<a[i];
    return 0;
}
