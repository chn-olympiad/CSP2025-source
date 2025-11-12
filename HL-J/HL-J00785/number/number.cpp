#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1000010];

int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    string s;
    cin>>s;
    int len=s.length();
    int sumn=0;
    for (int i=0;i<len;i++) {
        if (s[i]>='0'&&s[i]<='9') {
            a[++sumn]=s[i]-'0';
        }
    }
    sort(a+1,a+sumn+1);
    if (a[sumn]==0) {
        cout<<0;
        return 0;
    }
    for (int i=sumn;i>=1;i--) {
        cout<<a[i];
    }
    return 0;
}
