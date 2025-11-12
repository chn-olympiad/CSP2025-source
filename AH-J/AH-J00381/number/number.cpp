#include<bits/stdc++.h>
using namespace std;

string s;

long long a[100010],t=1;

bool cmp(int a,int b) {
    return a>b;
}

int main () {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for (int i=0;i<s.size();i++) {
        if (s[i]>='0'&&s[i]<='9') {
            a[t]=s[i]-'0';
            t++;
        }
    }
    sort(a+1,a+t,cmp);
    for (int i=1;i<t;i++) cout<<a[i];
    return 0;
}
