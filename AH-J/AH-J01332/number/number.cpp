#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i,p=0,n;
    string s;
    cin>>s;
    n=s.length();
    for(i=0;i<n;i++){
        if(s[i]>='0' && s[i]<='9'){
            a[p]=s[i]-'0';
            p++;
        }
    }
    sort(a,a+p);
    for(i=p-1;i>=0;i--)
        cout<<a[i];
    return 0;
}
