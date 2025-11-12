#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
string s;
int a[N],idx;

bool cmp(int x,int y) {
    return x>y;
}

int main() {
    //freopen("number4.in","r",stdin);
    //freopen("number4.out","w",stdout);
    cin>>s;
    int l=s.size();
    for (int i=0;i<s.size();i++) {
        if (s[i]>='0'&&s[i]<='9') {
            a[idx++]=(s[i]-'0');
        }
    }
    sort(a,a+idx,cmp);
    for (int i=0;i<idx;i++) cout<<a[i];
    return 0;
}
