#include<bits/stdc++.h>
using namespace std;;
bool cmp(int x,int y) {
    return x>y;
}
int a[1000005];
int j=1;
string s;
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++) {
        if(isdigit(s[i])) {
            a[j]=s[i]-'0';
            j++;
        }
    }
    sort(a+1,a+j+1,cmp);
    for(int i=1;i<j;i++) {
        cout<<a[i];
    }
    return 0;
}
