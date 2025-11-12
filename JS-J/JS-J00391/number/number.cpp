#include <bits/stdc++.h>
using namespace std;
string st;
short a[1000005];
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>st;
    int t=0;
    for(int i=0;i<st.size();i++) {
        if(isdigit(st[i])) {
            t++;
            a[t]=int(st[i]-'0');
        }
    }
    sort(a+1,a+t+1);
    for(int i=t;i>=1;i--) {
        cout<<a[i];
    }
    return 0;
}