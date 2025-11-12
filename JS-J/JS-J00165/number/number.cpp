#include<bits/stdc++.h>
using namespace std;
int n=1,a[1000010];
int main(){
    freopen("p1.in","r",stdin);
    freopen("p1.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[n]=int(s[i]-48);
            n++;
        }
    }
    n--;
    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }
    return 0;
}