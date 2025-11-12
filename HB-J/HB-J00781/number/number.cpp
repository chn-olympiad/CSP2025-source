#include<bits/stdc++.h>
using namespace std;
int n,a[1000000];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[n]=s[i];
            n++;
        }
    }
    sort(a,a+n);
    for(int i=9;i<n;i++) cout<<a[i];
    return 0;
}
